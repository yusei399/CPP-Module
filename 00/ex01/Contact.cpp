#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::set_info(int i)
{
	this->_index = i + 1;
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << info_name(i) << ": ";
		std::cin >> _info[i];
		if (std::cin.eof())
			std::exit(1);
		if (_info[i].empty())
		{
			std::cout << "empty is not valid\n"
						<< "retry : ";
			std::cin >> _info[i];
			if (std::cin.eof())
				std::exit(1);
		}
	}
}

std::string Contact::info_name(int i)
{
	if (i == FirstName)
		return ("First Name");
	else if (i == LastName)
		return ("Last Name");
	else if (i == NickName)
		return ("Nick Name");
	else if (i == PhoneNumber)
		return ("Phone number");
	else if (i == DarkestSecret)
		return ("Darkest secret");
	else
		return (NULL);
}

int	Contact::get_index(void)
{
	return this->_index;
}

std::string Contact::slice(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void Contact::display_header()
{
	std::cout << "|" << std::setw(10) << _index ;
	std::cout << "|" << std::setw(10) << slice(_info[FirstName]);
	std::cout << "|" << std::setw(10) << slice(_info[LastName]);
	std::cout << "|" << std::setw(10) << slice(_info[NickName])
			<< "|"<< std::endl;
}

void Contact::display_all(void)
{
	for (int i = FirstName; i <= DarkestSecret; i++)
		std::cout << info_name(i) << ": " << _info[i] << std::endl;
}
