#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private:
		ScavTrap(void);
	public:
		ScavTrap(const std::string &_name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap(void);
		void	attack(std::string const &target);
		void	guardGate(void);
		ScavTrap &operator=(const ScavTrap &rhs);
};

#endif