#include "Zombie.hpp"


void Zombie::announce(void) const
{
	std::cout << this->_name << ": Braiiiiiiinnnssss..." << std::endl;
}

void	Zombie::push_name(const std::string &name)
{
	this->_name = name;
}

Zombie::Zombie(const std::string &_name) : _name(_name)
{
	announce();
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " died!" << std::endl;
}

Zombie::Zombie(void) {}