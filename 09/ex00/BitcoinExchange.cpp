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

std::string trim(const std::string& string, const char* trimCharacterList = " \t\v\r\n")
{

	std::string result;
	std::string::size_type left = string.find_first_not_of(trimCharacterList);
	if (left != std::string::npos)
	{
		std::string::size_type right = string.find_last_not_of(trimCharacterList);
		result = string.substr(left, right - left + 1);
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

bool	validateDate(std::string s_date, int &i_year,int &i_month,int &i_day)
{
	char 	*c_p_year;
	char 	*c_p_month;
	char 	*c_p_day;
	

	// std::cout << "test1" << std::endl;
	c_p_year = strtok(const_cast<char*>(s_date.c_str()), "-");
	// std::cout << "test2" << std::endl;

	if (c_p_year == NULL)
		return (1);
	// std::cout << "test3" << std::endl;
	c_p_year = (char *)trim(c_p_year).c_str();
	// std::cout << "test4" << std::endl;
	if (xStrlen(c_p_year) != 4 || atoi(c_p_year) > MAX_YEAR || atoi(c_p_year) < MIN_YEAR )
		return (1);
	else
		i_year = atoi(c_p_year);
	// std::cout << "test5" << std::endl;
	c_p_month = strtok(NULL, "-");
	if (c_p_month == NULL)
		return (1);
	// std::cout << "test6" << std::endl;
	c_p_month = (char *)trim(c_p_month).c_str();
	if (xStrlen(c_p_month) != 2 || atoi(c_p_month) > MAX_MONTH || atoi(c_p_month) < MIN_MONTH)
		return (1);
	else
		i_month = atoi(c_p_month);
	c_p_day = strtok(NULL, "-");
	// std::cout << "test7" << std::endl;
	if (c_p_day == NULL)
		return (1);
	// std::cout << "test8" << std::endl;
	c_p_day = (char *)trim(c_p_day).c_str();
	if (xStrlen(c_p_day) != 2 || atoi(c_p_day) > Check_leap_year(i_year, i_month) || atoi(c_p_day) < MIN_DAY)
		return (1);
	else
		i_day = atoi(c_p_day);
	// std::cout << "test9" << std::endl;
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

bool Parse_date(std::string &line,BitcoinExchange &be)
{
	std::string data;
	float value;
	char *data_array;
	char *value_array;
	std::map<std::string,std::string>::iterator its;
	// int year, month, day;
	// std::string month_str, day_str;
	(void)be;
	std::cout << "pipe : " << std::count(line.begin(), line.end(), '|') << std::endl;

	if (std::count(line.begin(), line.end(), '|') > 1)
	{
		std::cout << "Error: file's line is not 'date | value'." << std::endl;
		return 1;
	}
	data_array = strtok(const_cast<char*>(line.c_str()), "|");
	std::cout << "data_array :"<< data_array << std::endl;
	if (!data_array)
	{
		std::cout << "Error: file's line is not 'date | value'." << std::endl;
		return 1;
	}
	value_array = strtok(NULL, "|");
	data = std::string(data_array);
	// if (validateDate(data, year, month, day))
	// {
	// 	std::cout << "Error: bad input " << std::endl;
	// 	return 1;
	// }

	if (!value_array)
	{
		std::cout << "Error: file's line is not 'date | value'." << std::endl;
		return 1;
	}
	else
	{
		if (isNumberArray(value_array))
		{
			std::cout << "Error:  input is not number " << std::endl;
			return 1;
		}
		else
		{
			std::cout << "value_array :"<< value_array << std::endl;
			value = atof(value_array);
			std::cout << "atof value :"<< value << std::endl;
		}
		if (value == 0 || value > 1000 || value < 0)
		{
			std::cout << "Error: value is not a float or a positive integer between 0 and 1000. " << std::endl;
			return 1;
		}
		
	}
	// std::cout << "data :"<< data << std::endl;
	std::cout << "value : "<< value_array << std::endl;

	its = be.getEntries().find(data);

	return true;
}