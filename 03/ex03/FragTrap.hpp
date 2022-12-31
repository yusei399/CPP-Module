#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string &_name);
		FragTrap(const FragTrap &copy);
		~FragTrap(void);
		FragTrap &operator=(const FragTrap &rhs);
		void	highFivesGuys(void);
};

#endif

