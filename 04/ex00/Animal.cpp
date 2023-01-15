#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[Animal] constructer is called()" << std::endl;
}

Animal::~Animal()
{
	std::cout << "[Animal] destructer is called()" << std::endl;
}

Animal::Animal(const std::string &type)
{
	this->type = type;
	std::cout << "[Animal] created with type" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	this->type = copy.type;
	std::cout << "[Animal] copy called()" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (this == &rhs)
		return(*this);
	else
	{
		this->type = rhs.type;
		return (*this);
	}
}

const std::string &Animal::getType()const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "animal sound" << std::endl; 
}