#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this == &other)
        return *this;

    // Perform the assignment here
    read_csv = other.read_csv;

    return *this;
}

void BitcoinExchange::addEntry(const std::string& key, const std::string& value)
{
    read_csv.emplace(key, value);
}

const std::map<std::string, std::string>& BitcoinExchange::getEntries() const
{
    return read_csv;
}


bool Linecheck(std::ifstream &ifs)
{
    std::string expected_line = "date | value";
    std::string actual_line;

    std::getline(ifs, actual_line);
    if (actual_line != expected_line)
    {
        std::cout << "Error: file's first line is not 'date | value'." << std::endl;
        return false;
    }
	std::cout << "first line is correct" << std::endl;
    return true;
}

int Check_leap_year(int year, int month)
{
	if (month == 2)
	{
		if (year % 4 == 0 && year % 100 != 0)
			return 29;
		else if (year % 400 == 0)
			return 29;
		else
			return 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		return 31;
}

size_t CountPipe(std::string line)
{
	size_t count = 0;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] == '|')
			count++;
	}
	return count;
}


bool Parse_date(std::string &line,BitcoinExchange &be)
{
	// std::string data;
	// float value;
	// char *data_araay;
	// char *value_array;
	// int year, month, day;
	// std::string month_str, day_str;
	(void)be;

	if (std::count(line.begin(), line.end(), '|') != 2)
	{
		std::cout << "Error: file's line is not 'date | value'." << std::endl;
		return false;
	}
	// std::cout << "line is correct" << std::endl;
	// return true;
}