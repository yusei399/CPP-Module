#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_damage;
	public:
		ClapTrap(void);
		ClapTrap(const std::string &_name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap(void);
		ClapTrap	&operator=(ClapTrap &rhs);
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};


#endif