#include "FragTrap.hpp"

FragTrap::~FragTrap(void)
{
	std::cout << "[FragTrap " << this->_name << "] (destructed) I'm dead :((((((" << std::endl;
}

FragTrap::FragTrap(const std::string &_name) : ClapTrap(_name)
{
	std::cout << "[FragTrap " << this->_name << "] (constructed) I'm born!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "[FragTrap " << this->_name << "] (copy-constructed) I wanna fall in mud..." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap " << this->_name << "] (highing five) High five guys!" << std::endl;
}