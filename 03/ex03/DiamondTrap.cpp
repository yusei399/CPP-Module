#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void){}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "[DiamondTrap " << this->_name << "] (destructed)" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &_name)
{
	std::cout <<  "[FragTrap " << this->_name << "] (destructed) I'm dead :((((((" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), _name(name)
{
	this->_energy = 50;
	std::cout << "[DiamondTrap " << this->_name << "] (constructed)" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy._name + "_clap_name"), ScavTrap(copy._name + "_clap_name"), FragTrap(copy._name + "_clap_name"), _name(copy._name)
{
	std::cout << "[DiamondTrap " << this->_name << "] (copy-constructed)" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "[DiamondTrap " << this->_name << "] (who am I?) this->_name: " << this->_name << std::endl;
	std::cout << "[DiamondTrap " << this->_name << "] (who am I?) ClapTrap::_name: " << ClapTrap::_name << std::endl;
}