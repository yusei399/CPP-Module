#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
# include <iostream>

class PhoneBook
{
	public:
		PhoneBook(void);
		void			displayEntries(void)	const;
		void			displayEntry(int i)		const;
		int				get_size(void)			const;
		void			addEntry(std::string array[3]);
	private:
		unsigned int	_size;
		int				_insert_id;
		Contact			_contacts[8];
};

#endif