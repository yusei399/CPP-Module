#include "BitcoinExchange.hpp"
#include <iostream>

#include <sstream>
#include <cstdlib>

static bool validateDate(const std::string& date) {
    if (date.empty()) {
        std::cout << "Error: Missing date." << std::endl;
        return false;
    }

    if (date.length() != 10) {
        std::cout << "Error: Bad date format." << std::endl;
        return false;
    }

    int year, month, day;
    char dash1, dash2;
    std::istringstream stream(date);
    stream >> year >> dash1 >> month >> dash2 >> day;

    if (stream.fail() || dash1 != '-' || dash2 != '-') {
        std::cout << "Error: Invalid date format." << std::endl;
        return false;
    }

    if (year < 0 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31) {
        std::cout << "Error: Invalid date values." << std::endl;
        return false;
    }

    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int daysInMonth = 31;

    switch (month) {
        case 2:
            daysInMonth = isLeapYear ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        default:
            break;
    }

    if (day > daysInMonth) {
        std::cout << "Error: Invalid day value for the given month." << std::endl;
        return false;
    }

    return true;
}


BitcoinExchange::BitcoinExchange(const char *input) {
    std::ifstream read_csv;
    read_csv.exceptions(std::ifstream::badbit);
    read_csv.open(input);
    if (!read_csv.is_open()) {
        std::cerr << "Failed to open database file" << std::endl;
        return;
    }

    std::string header;
    std::getline(read_csv, header);
    if (header != "date,exchange_rate") {
        std::cerr << "Invalid file header..." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(read_csv, line)) {
        if (read_csv.fail())
            continue;

        size_t i = line.find_first_of(",");
        if (i == std::string::npos) {
            std::cout << "Error: bad input." << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, i);

        i = line.find_first_not_of(",", i);
        const char* floatValue = line.c_str() + i;
        char* ep;
        float value = std::strtof(floatValue, &ep);
        if (value < 0) {
            std::cout << "Error: bad input." << floatValue << std::endl;
            continue;
        }

        _db.insert(std::make_pair(date, value));
    }
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    _db = other._db;
}

BitcoinExchange::~BitcoinExchange() {}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_db = other._db;
    }
    return *this;
}

void BitcoinExchange::parser(const char* inputFile) {
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
    bool dataFound = false;  // データが見つかったかどうかを示すフラグ

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
        char* ep;
        float value = std::strtof(floatValue, &ep);
        if (value < 0 || (value == 0 || value > 1000)) {
            std::cout << "Error: bad input." << floatValue << std::endl;
            continue;
        }

        ExchangeDatabase::iterator rate = _db.upper_bound(date);
        if (rate == _db.end()) {
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

        dataFound = true;  // データが見つかったことを示すフラグをセット
    }
	if (!dataFound) {
        std::cout << "Error: No data found in the CSV file." << std::endl;
    }
}
