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

        ExchangeDatabase _db;

    public:
        BitcoinExchange(const char* databaseFile);
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();

        void parser(const char *input);
        BitcoinExchange& operator=(const BitcoinExchange &rhs);

};

#endif
