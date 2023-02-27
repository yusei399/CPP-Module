#include "Weapon.hpp"

Weapon::Weapon(const std::string &_type) : _type(_type) {}

const std::string &Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(const std::string &_type)
{
	this->_type = _type;
}
