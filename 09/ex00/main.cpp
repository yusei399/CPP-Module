#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <input>\n";
		return 1;
	}

	try {
		BitcoinExchange exchange("data.csv");
		exchange.parser(argv[1]);
	} catch (std::ios_base::failure const &ex) {
		std::cerr << "Error File" << ex.what() << '\n';
	}
}