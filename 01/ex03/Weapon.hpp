#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon
{
	public:
		Weapon(const std::string &_type);
		const std::string	&getType(void)	const;
		void				setType(const std::string &_type);
	private:
		std::string	_type;
};

#endif
