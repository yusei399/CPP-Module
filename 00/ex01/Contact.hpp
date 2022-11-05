#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	public:
		int					get_index(void)			const;
		const std::string	&get_firstname(void)		const;
		const std::string	&get_lastname(void)		const;
		const std::string	&get_nickname(void)		const;
		void				set_index(int _index);
		void				set_firstname(std::string _firstname);
		void				set_lastname(std::string _lastname);
		void				set_nickname(std::string _nickname);
	private:
		int					_index;
		std::string			_firstname;
		std::string			_lastname;
		std::string			_nickname;
};

#endif