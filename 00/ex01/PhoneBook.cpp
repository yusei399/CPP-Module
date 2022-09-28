#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _size(0), _insert_id(0) {}

void PhoneBook::addEntry(std::string array[3])
{
	this->_contacts[this->_insert_id].push_firstname(array[0]);
	this->_contacts[this->_insert_id].push_firstname(array[1]);
	this->_contacts[this->_insert_id].push_lastname(array[2]);
	this->_insert_id = (this->_insert_id + 1) % 8;
	if (this->_size < 8)
		this->_size++;
}

void	PhoneBook::displayEntry(int i)const
{
	std::cout << "First Name:\n" << this->_contacts[i].get_firstname() << std::endl;
	std::cout << "Last Name\n" << this->_contacts[i].get_lastname() << std::endl;
	std::cout << "Nick Name\n" << this->_contacts[i].get_lastname() << std::endl;
}

int PhoneBook::get_size(void)const
{
	return (this->_size);
}

void PhoneBook::displayEntries(void)const
{
	unsigned int	i;
	unsigned int	j;

	while (i < this->_size)
	{
		std::cout << "|         ";
		std::cout << i;
		std::cout << "|";
		if (this->_contacts[i].get_firstname().length() > 10)
		{
			std::cout << this->_contacts[i].get_firstname().substr(0,9);
		}
		else
		{
			j = 0;
			while(j++ < 10 - this->_contacts[i].get_firstname().length())
				std::cout << " ";
			std::cout << this->_contacts[i].get_firstname();
		}
		std::cout << "|";
		if (this->_contacts[i].get_lastname().length() > 10)
		{
			std::cout << this->_contacts[i].get_lastname().substr(0,9);
			std::cout << ".";
		}
		else
		{
			j = 0;
			while(j++ < 10 - this->_contacts[i].get_lastname().length())
				std::cout << " ";
			std::cout << this->_contacts[i].get_lastname();
		}
		std::cout << "|";
		if (this->_contacts[i].get_nickname().length > 10)
		{
			std::cout << this->_contacts[i].get_nickname().substr(0, 9);
			std::cout << ".";
		}
		else
		{
			j = 0;
			while (j++ < 10 - this->_contacts[i].get_nickname().length())
				std::cout << " ";
			std::cout << this->_contacts[i].get_nickname();
		}
		std::cout << "|" << std::endl;
		i++;
	}
}
