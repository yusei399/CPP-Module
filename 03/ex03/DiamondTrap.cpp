#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap()
{
	this->_hp = FragTrap::_hp;
	
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << "destructed called()" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), _name(name)
{
	this->_energy = 50;
	std::cout << "DiamondTrap " << this->_name << "constructer called()" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy._name + "_clap_name"), ScavTrap(copy._name + "_clap_name"), FragTrap(copy._name + "_clap_name"), _name(copy._name)
{
	std::cout << "DiamondTrap " << this->_name << "copy_constructed called()" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this == &rhs)
		return (*this);
	else
	{
		this->_hp = rhs._hp;
		this->_energy = rhs._energy;
		this->_damage = rhs._damage;
		return (*this);
	}
}


void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->_name << "who am I? this->_name: " << this->_name << std::endl;
	std::cout << "DiamondTrap " << this->_name << "who am I? ClapTrap::_name: " << ClapTrap::_name << std::endl;
}
