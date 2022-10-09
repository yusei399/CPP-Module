#ifndef WRONGCAT_HPP 
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	/* data */
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat&);

	using WrongAnimal::operator=;
	void makeSound() const;
};

#endif