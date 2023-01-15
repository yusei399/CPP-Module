#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog&);
	Animal	&operator=(Animal &rhs);
	void	makeSound() const;

};



#endif