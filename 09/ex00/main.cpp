#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <sstream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::string line;
    std::vector<std::string> lines;
    BitcoinExchange be;

	try
	{
		std::ifstream csv("data.csv");
		if (!csv.is_open())
			throw std::runtime_error("Error: file not found");

		while (std::getline(csv, line))
		{
			std::string key, value;
			std::stringstream ss(line);

			std::getline(ss, key, ',');
			std::getline(ss, value, ',');

			be.addEntry(key, value);
		}
		
		// csv.close();
		for (const auto &i : be.getEntries())
			std::cout << i.first << ": " << i.second << std::endl;
		
		if (argc != 2)
		{
			std::cout << "Usage: ./bitcoin \"expression\"" << std::endl;
			return 1;
		}
		std::ifstream ifs(argv[1]);
		if (!ifs.is_open())
			std::cerr << "Error: file not found" << std::endl;
		if (Linecheck(ifs))
		{
			while (std::getline(ifs, line, '\n'))
			{
				Parse_date(line, be);
			}
		}
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

    return 0;
}

