#include "ScavTrap.hpp"

// ScavTrap::ScavTrap(void) {}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << "destructer called()" << std::endl;
}

ScavTrap::ScavTrap(const std::string &_name) : ClapTrap(_name)
{
	std::cout << "ScavTrap " << this->_name << "constructer called()" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap " << this->_name << "copy_constructed called()" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << "guarding called()" << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_energy >= 5)
	{
		std::cout << "ScavTrap " << this->_name << "attacking " << target << ", dealing " << this->_damage << " damage I'mma kill youuuuuuuuu" << std::endl;
		this->_energy -= 5;
	}
}