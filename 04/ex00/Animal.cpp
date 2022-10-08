#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal create" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destroy" << std::endl;
}

Animal::Animal(const std::string &type)
{
	this->type = type;
	std::cout << "Animal created with arg ctor" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	this->type = copy.type;
	std::cout << "Animal created with arg ctor" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	this->type = rhs.type;
	return (*this);
}

const std::string &Animal::getType()const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "*animal sound*" << std::endl; 
}