#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	FragTrap(void);
public:
	FragTrap(const std::string &_name);
	FragTrap(const FragTrap &copy);
	~FragTrap(void);
	void	highFivesGuys(void);
	using	ClapTrap::operator=;
};

#endif