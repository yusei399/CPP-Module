#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <string>
#include <map>

class BitcoinExchange {
private:
    BitcoinExchange();

    typedef std::greater_equal<std::string> DateComparator;
    typedef std::map<std::string, float, DateComparator> ExchangeDatabase;

    ExchangeDatabase _database;

public:
    BitcoinExchange(const char* databaseFile);
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    BitcoinExchange& operator=(const BitcoinExchange& other);

    void applyExchangeRate(const char* inputFile);
};

#endif
