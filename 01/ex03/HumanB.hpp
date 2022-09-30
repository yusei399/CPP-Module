#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class	HumanB
{
	public:
		HumanB(const std::string &_name);
		void		attack(void)	const;
		void		setWeapon(Weapon *_weapon);
	private:
		const std::string	&_name;
		Weapon				*_weapon;
};

#endif