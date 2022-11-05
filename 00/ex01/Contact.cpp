#include "Contact.hpp"

int	Contact::get_index(void) const
{
	return (this->_index);
}

const std::string	&Contact::get_firstname(void) const
{
	return (this->_firstname);
}

const std::string	&Contact::get_lastname(void) const
{
	return (this->_lastname);
}

const std::string	&Contact::get_nickname(void) const
{
	return (this->_nickname);
}

void	Contact::set_index(int _index)
{
	this->_index = _index;
}

void	Contact::set_firstname(std::string _firstname)
{
	this->_firstname = _firstname;
}

void	Contact::set_lastname(std::string _lastname)
{
	this->_lastname = _lastname;
}

void	Contact::set_nickname(std::string _nickname)
{
	this->_nickname = _nickname;
}