#include "ClapTrap.hpp"


ClapTrap::~ClapTrap(void)
{
	std::cout << "Claptrap " << this->_name << "destructer called()" << std::endl;
}

ClapTrap::ClapTrap(const std::string &_name) : _name(_name), _hp(10), _energy(10), _damage(0)
{
	std::cout << "Claptrap " << this->_name << "constructer called()" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) :  _name(copy._name), _hp(copy._hp), _energy(copy._energy), _damage(copy._damage)
{
	std::cout << "Claptrap " << this->_name << "copy-constructer called()" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap &rhs)
{
	this->_hp = rhs._hp;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	std::cout << "Claptrap " << this->_name << "being assigned Finally, equality was achieved." << std::endl;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
		std::cout << "Claptrap " << this->_name << "attacking " << target << ", dealing " << this->_damage << " damage) Demolition commenced." << std::endl;
		this->_energy -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (static_cast<int>(this->_hp) - static_cast<int>(amount) < 0)
		this->_hp = 0;
	else
		this->_hp -= amount;
	std::cout << "Claptrap " << this->_name << "taking " << amount << " damage; hp now: " << this->_hp << " It burns..." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hp += amount;
	this->_energy -= 1;
	std::cout << "Claptrap " << this->_name << "repaired " << amount << " points; hp now: " << this->_hp << "I love it." << std::endl;
}