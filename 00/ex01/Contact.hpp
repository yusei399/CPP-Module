#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string.h>

class Contact
{
private:
	int			index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
public:
	Contact();
	~Contact();
	int					get_index(void)			const;
	const std::string	&get_firstname(void)		const;
	const std::string	&get_lastname(void)		const;
	const std::string	&get_nickname(void)		const;
	void				push_index(int index);
	void				push_firstname(std::string first_name);
	void				push_lastname(std::string last_name);
	void				push_nickname(std::string nickname);
};

#endif