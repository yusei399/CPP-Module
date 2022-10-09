#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &rhs);
		void	makeSound() const;
};



#endif