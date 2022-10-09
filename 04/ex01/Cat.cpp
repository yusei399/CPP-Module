#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << this->type << "create with defaut" << std::endl;
}

Cat::~Cat()
{
	std::cout << this->type << "destory" << std::endl;
}

Cat::Cat(const Cat&) : Animal("Cat")
{
	std::cout << this->type << " create with copy" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "* meow! cat noises *" << std::endl;
}
