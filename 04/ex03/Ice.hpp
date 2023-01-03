#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

class Ice : public AMateria
{
	public:
		Ice(/* args */);
		Ice(const Ice &copy);
		~Ice();

		Ice &operator=(const Ice &rhs);
		AMateria *clone(void) const;
		void use(ICharacter &target);
};

#endif
