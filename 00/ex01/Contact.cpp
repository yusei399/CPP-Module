#include "Contact.hpp"

int Contact::get_index(void)const
{
	return (this->_index);
}

const std::string &Contact::get_firstname(void)const
{
	return (this->_first_name);
}

const std::string	&Contact::get_lastname(void) const
{
	return (this->_lastname);
}

const std::string &Contact::get_nickname(void)const
{
	return (this->_nickname);
}

void Contact::push_index(int _index)
{
	this->_index = _index;
}

void	Contact::push_firstname(std::string _firstname)
{
	this->_firstname = _firstname;
}

void	Contact::push_lastname(std::string _lastname)
{
	this->_lastname = _lastname;
}

void	Contact::push_nickname(std::string _nickname)
{
	this->_nickname = _nickname;
}
