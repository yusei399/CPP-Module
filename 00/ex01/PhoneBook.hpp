#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
#include <algorithm>
#include <cstdlib>

class	PhoneBook
{
	public:
		PhoneBook(void);
		void			search_contact(void);
		void			add_entry(void);
	private:
		int				_index;
		Contact			_contacts[8];
};

#endif
