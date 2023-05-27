#include "BitcoinExchange.hpp"
#include <iostream>

#include <sstream>
#include <cstdlib>

static bool validateDate(std::string& date) {
    if (date.length() != 10)
    {
		std::cout << "Error: bad input." << date<< std::endl;
		return false;
	}

    std::istringstream stream(date);
    int value;
    stream >> value;
    if (stream.fail() || value < 0 || value > 9999 || stream.peek() != '-')
    {
		std::cout << "Error: bad input." << date<< std::endl;
		return false;
	}
    stream.ignore();
    stream >> value;
    if (stream.fail() || value < 1 || value > 12 || stream.peek() != '-')
    {
		std::cout << "Error: bad input." << date<< std::endl;
		return false;
	}
    stream.ignore();
    stream >> value;
    if (stream.fail() || value < 1 || value > 31 || !stream.eof())
    {
		std::cout << "Error: bad input." << date<< std::endl;
		return false;
	}
    return true;
}

static bool parseLine(std::ifstream& inputFile, const char* delimiters, bool checkValue, std::string& date, float& value) {
    std::string line;
    std::getline(inputFile, line);

    if (inputFile.fail())
        return false;
    size_t i = line.find_first_of(delimiters);
    if (i == std::string::npos)
    {
		std::cout << "Error: bad input." << line<< std::endl;
		return false;
	}
    date = line.substr(0, i);
    if (!validateDate(date))
        return false;
    i = line.find_first_not_of(delimiters, i);
    const char* floatValue = line.c_str() + i;
    char* endPointer;
    value = std::strtof(floatValue, &endPointer);
    if (value < 0 || (checkValue && (value == 0 || value > 1000)))
    {
		std::cout << "Error: bad input." << floatValue << std::endl;
		return false;
	}
    return true;
}

BitcoinExchange::BitcoinExchange(const char* databaseFile) {
    std::ifstream dbFile;
    dbFile.exceptions(std::ifstream::badbit);
    dbFile.open(databaseFile);
    if (dbFile.fail())
        throw std::ios_base::failure("Failed to open file");

    std::string header;
    std::getline(dbFile, header);
    if (header != "date,exchange_rate")
        std::cerr << "Invalid file header...\n";

    while (!dbFile.eof()) {
        std::string date;
        float value;

        if (!parseLine(dbFile, ",", false, date, value))
            continue;
        _database.insert(std::make_pair(date, value));
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    _database = other._database;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_database = other._database;
    }
    return *this;
}

static std::string getValueString(float value) {
    std::ostringstream stream;
    stream << std::fixed << value;

    std::string str = stream.str();
    str.erase(str.find_last_not_of("0.") + 1);
    return (str);
}

void BitcoinExchange::applyExchangeRate(const char* inputFile) {
    std::ifstream input;
    input.exceptions(std::ifstream::badbit);
    input.open(inputFile);
    if (input.fail())
        throw std::ifstream::failure("Failed to open file");

    std::string header;
    std::getline(input, header);
    if (header != "date | value")
    {
		std::cout << "Error: bad input." << header << std::endl;
		return ;
	}
    while (!input.eof()) {
        std::string date;
        float value;
        if (!parseLine(input, " |", true, date, value))
            continue;

        ExchangeDatabase::iterator rate = _database.upper_bound(date);
        if (rate == _database.end()) {
            std::cerr << "Error: No date before: " << date << "\n";
            continue;
        }

        const float newValue = value * rate->second;
        std::cout << date << " => " << getValueString(value)<< " = " << getValueString(newValue) << "\n";
    }
}




