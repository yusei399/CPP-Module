#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "[" << this->type << "]" << "default constructer is called()" << std::endl;
}

Cat::~Cat()
{
	std::cout << "[" << this->type << "]" << "destructer is called()" << std::endl;
}

Cat::Cat(const Cat&) : Animal("Cat")
{
	std::cout <<"["<< this->type << "]"<< "copy constructer is called()" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "* meow! cat noises *" << std::endl;
}
