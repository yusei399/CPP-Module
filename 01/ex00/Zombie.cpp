#include "Zombie.hpp"

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": Braiiiiiiinnnssss..."  << std::endl;
}

Zombie::Zombie(const std::string &_name) : _name(_name) { }

Zombie::~Zombie(void)
{
	std::cout << this->_name << "name" << std::endl;
}

