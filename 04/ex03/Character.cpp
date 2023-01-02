#include "Character.hpp"

Character::Character()
{
	std::cout << "default constructer is called()" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventry[i] = 0;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventry[i] != 0)
		{
			delete _inventry[i];
		}
	}
	std::cout << "destructer is called()" << std::endl;
}

Character &Character::operator=(const Character &rhs)
{
	this->_type = rhs._type;

}