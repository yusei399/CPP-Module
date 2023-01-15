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

Cat &Cat::operator=(const Cat &rhs)
{
	if (this == &rhs)
		return (*this);
	else
	{
		this->type = rhs.type;
		return (*this);
	}
}

void Cat::makeSound() const
{
	std::cout << "* meow! cat noises *" << std::endl;
}
