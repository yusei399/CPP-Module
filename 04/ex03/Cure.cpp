#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "default constructer is called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria("cure")
{
	*this = copy;
	std::cout << "copy constructer is called()" << std::endl;
} 


Cure::~Cure()
{
	std::cout << "destructer is called " << std::endl;
}


Cure &Cure::operator=(const Cure &rhs)
{
	if (this == &rhs)
		return (*this);
	else
	{
		(void)rhs;
		return (*this);
	}
}

AMateria *Cure::clone(void) const
{
	AMateria *clone = new Cure();

	return (clone);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}