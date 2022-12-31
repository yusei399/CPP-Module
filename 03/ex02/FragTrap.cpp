#include "FragTrap.hpp"

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " destructed called()" << std::endl;
}

FragTrap::FragTrap(const std::string &_name) : ClapTrap(_name)
{
	std::cout << "FragTrap " << this->_name << "constructed called()" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap " << this->_name << "copy_constructed called()" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << "highing five  calld()" << std::endl;
}
