#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_materia[i] = 0;
	}
	std::cout << "default constructer is called()" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "copy constructer is called()" << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	std::cout << "destructer is called ()" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] != 0)
			delete _materia[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	for (size_t i = 0; i < 4; i++)
	{
		delete this->_materia[i];
		if (rhs._materia[i])
			this->_materia[i] = rhs._materia[i];
		else
			this->_materia[i] = 0;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *target)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] == 0)
			_materia[i] = target;
			std::cout << "MateriaSource learn Materia" << std::endl;
			return;
	}
	std::cout << "[MateriaSource] MateriaSource cannot learn more Materia" << std::endl;
}


AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	std::cout << "MateriaSource Unknow materia type" << std::endl;
	return 0;
}