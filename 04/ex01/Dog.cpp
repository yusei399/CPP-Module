#include "Dog.hpp"

Dog::Dog() :Animal("Dog")
{
	std::cout << "Animal create" << std::endl;
}

Dog::~Dog()
{
	std::cout << this->type << "destory" << std::endl;
}

Dog::Dog(const Dog&) : Animal("Dog")
{
	std::cout << this->type << "create" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "* bark! Dog noises *" << std::endl;
}
