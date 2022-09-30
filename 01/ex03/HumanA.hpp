#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(const std::string &name, Wepon &_wepon);
		void				attack(void)	const;
	private:
		const std::string &_name;
		Weapon				&_weapon;
};


#endif