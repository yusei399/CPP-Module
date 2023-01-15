#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << this->type << "created with default" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << this->type << "destroy" << std::endl;
}


WrongCat::WrongCat(const WrongCat&) : WrongAnimal("WrongCat")
{
	std::cout << this->type << "create copy" << std::endl;
}


WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	if (this == &rhs)
		return (*this);
	else
	{
		this->type = rhs.type;
		return (*this);
	}
}

void	WrongCat::makeSound() const
{
	std::cout << "wrong cat noises" << std::endl;
}
