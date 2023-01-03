#include "Ice.hpp"

Ice::Ice() :AMateria("ice")
{
	std::cout << "constructer is called()" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria("ice")
{
	*this = copy;
	std::cout << "copy constructer is called()" << std::endl;
}

Ice::~Ice()
{
	std::cout << "destructer is called()" << std::endl;
}

Ice &Ice::operator=(const Ice &rhs)
{
	(void)rhs;
	return (*this);
}

AMateria *Ice::clone(void) const
{
	AMateria *clone = new Ice();

	return (clone);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

