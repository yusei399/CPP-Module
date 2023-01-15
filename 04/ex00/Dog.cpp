#include "Dog.hpp"

Dog::Dog() :Animal("Dog")
{
	std::cout << "[Dog] default constructer is called()" << std::endl;
}

Dog::~Dog()
{
	std::cout << "["<< this->type << "]" << "destructer is called()" << std::endl;
}

Dog::Dog(const Dog&) : Animal("Dog")
{
	std::cout << "["<< this->type << "]" << "copy constructer is called()" << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	if (this == &rhs)
		return (*this);
	else
	{
		this->type = rhs.type;
		return (*this);
	}
}

void Dog::makeSound() const
{
	std::cout << "bark" << std::endl;
}
