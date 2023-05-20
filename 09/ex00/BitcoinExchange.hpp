#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <map>
#include <vector>
#include <string>

#define MAX_YEAR 2023
#define MIN_YEAR 2008
#define MAX_MONTH 12
#define MIN_MONTH 1
#define MIN_DAY 1


class BitcoinExchange
{
private:
    std::map<std::string, std::string> read_csv;
public:
    BitcoinExchange();
    ~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &be);
    void addEntry(const std::string& key, const std::string& value);
    const std::map<std::string, std::string>& getEntries() const;
};

bool Linecheck(std::ifstream &ifs);
bool Parse_date(std::string &line,BitcoinExchange &be);

#endif