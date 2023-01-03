#include "Character.hpp"

Character::Character()
{
	std::cout << "default constructer is called()" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventry[i] = 0;
	}
}

Character::Character(std::string type) : _type(type)
{
	std::cout << "[Character] Pram Constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		_inventry[i] = 0;
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

Character::Character(const Character &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventry[i]  != 0)
		{
			delete _inventry[i];
		}
	}
	std::cout << "copy constructer is called()" << std::endl;
	*this = copy;
}

Character &Character::operator=(const Character &rhs)
{
	this->_type = rhs.getName();
	for (int i = 0; i < 4; i++)
	{
		delete _inventry[i];
		if (rhs._inventry[i])
		{
			this->_inventry[i] = rhs._inventry[i];
		}
		else
		{
			this->_inventry[i] = 0;
		}
	}
	return (*this);
}

std::string const &Character::getName() const{
	return _type;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventry[i] == 0)
		{
			_inventry[i] = m;
			std::cout << "AMatemria is equipped" << std::endl;
			return;
		}
	}
	std::cout << "There is AMateria in this index" << std::endl;
}


void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
		std::cout << "Invaild Index " << std::endl;
	else if (_inventry[idx] != 0)
	{
		_inventry[idx] = 0;
	}
	else
		std::cout << "There is AMateria in this index " << std::endl;
}


void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 4)
		std::cout << "Invalid Index" << std::endl;
	else if (_inventry[idx] != 0)
		_inventry[idx]->use(target);
	else
		std::cout << "There isn't Materia in this index" << std::endl;
}

