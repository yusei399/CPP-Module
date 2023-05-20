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


bool isNumberArray(char* value_char_array)
{
    int i = 0;
    while (value_char_array[i])
    {
        if (!isdigit(value_char_array[i]))
            return false;
        i++;
    }
    
    if (value_char_array[i - 1] == '.') // 最後が '.' の場合をはじく
        return false;
    
    return true;
}

bool Parse_date(std::string &line,BitcoinExchange &be)
{
	std::string data;
	// float value;
	char *data_array;
	char *value_array;
	// int year, month, day;
	// std::string month_str, day_str;
	(void)be;
	std::cout << std::count(line.begin(), line.end(), '|') << std::endl;

	if (std::count(line.begin(), line.end(), '|') > 1)
	{
		std::cout << "Error: file's line is not 'date | value'." << std::endl;
		return 1;
	}
	data_array = strtok(const_cast<char*>(line.c_str()), "|");
	return true;

	value_array = strtok(NULL, "|");
	data = std::string(data_array);
	std::cout << data << std::endl;
}