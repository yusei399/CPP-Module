#include <PhoneBook.hpp>

PhoneBook::PhoneBook() : _index(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_entry(void)
{
	_contacts[_index % 8].set_info(_index % 8);
	_index++;
	std::cout << "Contact successfully" << std::endl;
}

bool isNumeric(std::string const &str)
{
	return !str.empty() && str.find_first_not_of("0123456789") == std::string::npos;
}

void PhoneBook::search_contact(void)
{
	std::string input;
	int	index;

	if (this->_index == 0)
	{
		std::cout << "Empty Data" << std::endl;
		return ;
	}
	for (int i = 0; i < 8 && i < this->_index; i++)
		_contacts[i].display_header();
	while (!isNumeric(input))
	{
		std::cout << "INdex :";
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::exit(1);
	}
	index = std::atoi(input.c_str());
	for (int i = 0; i < 8; i++)
	{
		if (index == _contacts[i].get_index() && index > 0)
		{
			_contacts[i].display_all();
			return;
		}
	}
	if (index > 8)
		std::cout << "This index is out of range" << std::endl;
	else
		std::cout << "This index is not exist" << std::endl;
}