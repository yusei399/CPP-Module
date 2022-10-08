#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap(void);
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &copy);
		~DiamondTrap(void);
		using				ClapTrap::operator=;
		using				ScavTrap::attack;
		void				whoAmI(void);
};


#endif