#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phone_book;
	std::string input;

	int i = 1;
	while (1)
	{
		if (i == 1)
		{
			std::cout << "command >";
			i = 0;
		}
		std::getline(std::cin, input);
		if (input == "ADD")
			phone_book.add_entry();
		else if (input == "SEARCH")
		{
			phone_book.search_contact();
			std::cout << "command >";
		}
		else if (input == "EXIT" || std::cin.eof())
		{
			std::cout << "\nEXIT" << std::endl;
			break;
		}
		else
			std::cout << "command >";
	}
	return (0);
}
