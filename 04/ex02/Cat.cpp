#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << this->type << "create with defaut" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << this->type << "destory" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this == &rhs)
		return (*this);
	else
	{
		this->_brain = rhs._brain;
		return(*this);
	}
}

Cat::Cat(const Cat&) : Animal("Cat")
{
	std::cout << this->type << " create with copy" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "* meow! cat noises *" << std::endl;
}
