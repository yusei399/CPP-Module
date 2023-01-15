#ifndef WRONGCAT_HPP 
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat&);

		WrongAnimal	&operator=(WrongAnimal &rhs);
		void makeSound() const;
};

#endif