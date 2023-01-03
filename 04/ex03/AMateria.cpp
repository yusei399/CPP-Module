#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "default constructer is called()" << std::endl;
}


AMateria::~AMateria()
{
	std::cout << "destructer is called()" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "copy constructer is called()" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "A materia use on" << target.getName() << std::endl;
}

