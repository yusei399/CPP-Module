#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hp = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "default constructer called()";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " destructed called()" << std::endl;
}

FragTrap::FragTrap(const std::string &_name) : ClapTrap(_name)
{
	_hp = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "FragTrap " << this->_name << "constructed called()" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap " << this->_name << "copy_constructed called()" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	if (this == &rhs)
		return (*this);
	else
	{
		this->_hp = rhs._hp;
		this->_damage = rhs._damage;
		this->_energy = rhs._energy;
		return (*this);
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << "highing five  calld()" << std::endl;
}
