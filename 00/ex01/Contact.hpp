#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class	Contact
{
	public:
		Contact();
		~Contact();
		int get_index(void);
		void set_info(int index);
		void display_header(void);
		void display_all(void);
		std::string slice(std::string str);
		std::string info_name(int i);
	private:
		std::string	_info[5];
		int	_index;
		enum
		{
			FirstName,
			LastName,
			NickName,
			PhoneNumber,
			DarkestSecret
		};
};

#endif