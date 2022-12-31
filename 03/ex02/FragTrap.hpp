#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string &_name);
		FragTrap(const FragTrap &copy);
		~FragTrap(void);
		void	highFivesGuys(void);
		FragTrap &operator=(const FragTrap &rhs);
};

#endif