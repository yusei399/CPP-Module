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

void	WrongCat::makeSound() const
{
	std::cout << "* woem! wrong cat noises *" << std::endl;
}
