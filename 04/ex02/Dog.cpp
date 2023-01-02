#include "Dog.hpp"

Dog::Dog() :Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Animal create" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << this->type << "destory" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this == &rhs)
		return (*this);
	else
	{
		this->_brain = rhs._brain;
		return(*this);
	}
}

Dog::Dog(const Dog&) : Animal("Dog")
{
	std::cout << this->type << "create" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "* bark! Dog noises *" << std::endl;
}
