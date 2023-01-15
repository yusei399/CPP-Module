#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat&);
		Animal &operator=(Animal &rhs);
		void makeSound()const;
};

#endif
