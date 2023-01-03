#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

class Cure
{
	public:
		Cure(/* args */);
		Cure(const Cure &copy);
		~Cure();

		Cure &operator=(const Cure &rhs);
		AMateria *clone(void) const;
		void use(ICharacter &target);
};


#endif