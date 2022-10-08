#ifndef ANIMAl_HPP
#define ANIMAl_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
			Animal();
			virtual ~Animal();
			Animal(const Animal &copy);
			Animal &operator=(const Animal &rhs);
			const std::string &getType() const;
			virtual void makeSound() const;
	public:
		Animal(const std::string &type);
		std::string type;
};


#endif