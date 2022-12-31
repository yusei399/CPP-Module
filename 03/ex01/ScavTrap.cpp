#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_hp = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "deafult constructer called()" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << "destructed called()" << std::endl;
}

ScavTrap::ScavTrap(const std::string &_name) : ClapTrap(_name)
{
	_hp = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "ScavTrap " << this->_name << "constructed called()" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap " << this->_name << "copy_constructed called()" << std::endl;
}

void	ScavTrap::guardGate(void)
{

	std::cout << "ScavTrap " << this->_name << "guarding called()" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	this->_hp = rhs._hp;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	return (*this);
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_energy >= 1)
	{
		std::cout << "ScavTrap " << this->_name << "attacking " << target << ", dealing " << this->_damage << " damage I'mma kill youuuuuuuuu" << std::endl;
		this->_energy -= 1;
	}
}
