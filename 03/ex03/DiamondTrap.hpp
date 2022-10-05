#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap(const std::string &_name);
	~DiamondTrap();
	using	ClapTrap::operator=;
};


#endif