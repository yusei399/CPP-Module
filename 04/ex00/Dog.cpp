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

void Dog::makeSound() const
{
	std::cout << "* bark! Dog noises *" << std::endl;
}
