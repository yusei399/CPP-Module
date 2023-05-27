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

BitcoinExchange::BitcoinExchange(const char* databaseFile) {
    std::ifstream dbFile;
    dbFile.exceptions(std::ifstream::badbit);
    dbFile.open(databaseFile);
    if (!dbFile.is_open()) {
        std::cerr << "Failed to open database file...\n";
        return;
    }

    std::string header;
    std::getline(dbFile, header);
    if (header != "date,exchange_rate") {
        std::cerr << "Invalid file header...\n";
        return;
    }

    std::string line;
    while (std::getline(dbFile, line)) {
        if (dbFile.fail())
            continue;

        size_t i = line.find_first_of(",");
        if (i == std::string::npos) {
            std::cout << "Error: bad input." << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, i);

        i = line.find_first_not_of(",", i);
        const char* floatValue = line.c_str() + i;
        char* endPointer;
        float value = std::strtof(floatValue, &endPointer);
        if (value < 0) {
            std::cout << "Error: bad input." << floatValue << std::endl;
            continue;
        }

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


void BitcoinExchange::applyExchangeRate(const char* inputFile) {
    std::ifstream input;
    input.exceptions(std::ifstream::badbit);
    input.open(inputFile);
    if (!input.is_open()) {
        std::cerr << "Error: Cannot open file" << std::endl;
        return;
    }

    std::string header;
    std::getline(input, header);
    if (header != "date | value") {
        std::cout << "Error: bad input." << header << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input, line)) {
        if (input.fail())
            continue;

        size_t i = line.find_first_of(" |");
        if (i == std::string::npos) {
            std::cout << "Error: bad input." << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, i);
        if (!validateDate(date))
            continue;

        i = line.find_first_not_of(" |", i);
        const char* floatValue = line.c_str() + i;
        char* endPointer;
        float value = std::strtof(floatValue, &endPointer);
        if (value < 0 || (value == 0 || value > 1000)) {
            std::cout << "Error: bad input." << floatValue << std::endl;
            continue;
        }

        ExchangeDatabase::iterator rate = _database.upper_bound(date);
        if (rate == _database.end()) {
            std::cerr << "Error: No date before: " << date << "\n";
            continue;
        }

        std::ostringstream stream;
        stream << std::fixed << value;

        std::string str = stream.str();
        str.erase(str.find_last_not_of("0.") + 1);

        const float newValue = value * rate->second;

        std::ostringstream newValueStream;
        newValueStream << std::fixed << newValue;

        std::string newValueStr = newValueStream.str();
        newValueStr.erase(newValueStr.find_last_not_of("0.") + 1);

        std::cout << date << " => " << str << " = " << newValueStr << "\n";
    }
}
