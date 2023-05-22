#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this == &other)
        return *this;

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
	// std::cout << "first line is correct" << std::endl;
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

std::string trim(const std::string& string, const char* trimCharacterList = " \t\v\r\n")
{

	std::string result;
	std::string::size_type left = string.find_first_not_of(trimCharacterList);
	if (left != std::string::npos)
	{
		std::string::size_type right = string.find_last_not_of(trimCharacterList);
		result = string.substr(left, right - left + 1);
		// std::cout << "result : " << result << std::endl;
	}
	return (result);
}

size_t xStrlen(char *str)
{
	if(!str)
		return (0);
	size_t i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	validateDate(std::string date, int &year, int &month)
{
	char 	*c_p_year;
	char 	*c_p_month;
	// char 	*c_p_day;
	// std::cout << "data :"<< date << std::endl;
	// std::cout << "year :"<< year << std::endl;
	// std::cout << "month :"<< month << std::endl;
	// std::cout << "day :"<< day << std::endl;
	

	c_p_year = strtok(const_cast<char*>(date.c_str()), "-");

	// if (c_p_year == NULL)
	// 	return (1);
	c_p_year = (char *)trim(c_p_year).c_str();
	std::cout << "\033[32m" << "c_p_year :"<< c_p_year << "\033[0m" << std::endl; 
	if (strlen(c_p_year) != 4 || atoi(c_p_year) > 2023 || atoi(c_p_year) < 2008)
		return 1;
	else year = atoi(c_p_year);
	std::cout << "\033[31m" << "year :"<< year << "\033[0m" << std::endl;
	c_p_month = strtok(NULL, "-");
	std::cout << "\033[32m" << "c_p_month :"<< c_p_month << "\033[0m" << std::endl;
	std::cout << "month :"<< month << std::endl;
	// if (c_p_month == NULL)
	// 	return (1);
	// c_p_month = (char *)trim(c_p_month).c_str();
	// if (xStrlen(c_p_month) != 2 || atoi(c_p_month) > MAX_MONTH || atoi(c_p_month) < MIN_MONTH)
	// 	return (1);
	// else
	// 	month = atoi(c_p_month);
	// c_p_day = strtok(NULL, "-");
	// // std::cout << "day :"<< day << std::endl;
	// if (c_p_day == NULL)
	// 	return (1);
	// c_p_day = (char *)trim(c_p_day).c_str();
	// if (xStrlen(c_p_day) != 2 || atoi(c_p_day) > Check_leap_year(year, month) || atoi(c_p_day) < MIN_DAY)
	// 	return (1);
	// else
	// 	day = atoi(c_p_day);
	return (1);
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

bool Parse_date(std::string& line,BitcoinExchange &be)
{
	std::string date;
	// float value;
	char *date_array;
	char *value_array;
	// float result;
	int year, month;
	// std::string month_str = "", day_str = "";
	// (void)be;
		std::cout << "start line: " << line << std::endl;
	std::cout << "pipe count : " << std::count(line.begin(), line.end(), '|') << std::endl;
	if (std::count(line.begin(), line.end(), '|') > 1 || std::count(line.begin(), line.end(), '|') <= 0)
	{
		std::cout << "Error: file's line is not 'date | value'." << std::endl;
		return 1;
	}

	date_array = strtok(const_cast<char*>(line.c_str()), "|");
	std::cout << "date_array :"<< date_array << std::endl;
	if (!date_array)
	{
		std::cout << "Error: file's line is not 'date | value'." << std::endl;
		return 1;
	}
	value_array = strtok(NULL, "|");
	std::cout << "value_array :"<< value_array << std::endl;
	date = std::string(date_array);
	std::cout << "date :"<< date << std::endl;
	if (validateDate(date, year, month))
	{
		std::cout << "Error: date is not a valid date. test1 " << date << std::endl;
		return 1;
	}
	// date_array = strtok(const_cast<char*>(line.c_str()), "|");	
	// if (value_array == NULL)
	// {
	// 	std::cout << "Error: file's line is not 'date | value'." << date << std::endl;
	// 	return 1;
	// }
	// else
	// {
	// 	if (isNumberArray(value_array))
	// 	{
	// 		std::cout << "Error:  input is not number " << std::endl;
	// 		return 1;
	// 	}
	// 	else
	// 	{
	// 		// std::cout << "value_array :"<< value_array << std::endl;
	// 		value = atof(value_array);
	// 		// std::cout << "atof value :"<< value << std::endl;
	// 	}
	// 	if (value == 0 || value > 1000 || value < 0)
	// 	{
	// 		std::cout << "Error: value is not a float or a positive integer between 0 and 1000. " << std::endl;
	// 		return 1;
	// 	}
		
	// }
	// std::cout << "value : "<< value_array << std::endl;

	// std::map<std::string, std::string>::const_iterator its = be.getEntries().find(trim(date));
	// std::cout << "first : "<< its->first << std::endl;
	// std::cout << "second : "<< its->second << std::endl;
	// if (its != be.getEntries().end())
	// {
	// 	result = value * atof(its->second.c_str());
	// 	std::cout << "result : "<< result << std::endl;
	// }
	// else
	// {
	// 	std::cout << "Error: date is not a valid date. test2" << std::endl;
	// 	return 1;
	// }
	// if (1 <= month && month <= 9)
	// 	month_str = "0"; 
	// if (1 <= day && day <= 9) 
	// 		day_str = "0";
	// 	day_str = "0";
	// std::cout << year << "-" << month_str << month << "-" << day_str << day << " => " << value << " = " << result << std::endl;
	// return true;
	(void)be;
	std::cout << "\033[31m" << "end line: " << line << "\033[0m" << std::endl;
	std::cout << "------------------------------------------------------------"<< std::endl;
	return true;
}
