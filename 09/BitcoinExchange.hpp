# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, double> read_csv;
public:
	BitcoinExchange();
	~BitcoinExchange();
};

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

# endif