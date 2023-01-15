#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main()
{
	Animal	*pointers[20];

	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
			pointers[i] = new Dog;
		else
			pointers[i] = new Cat;
	}
	pointers[4]->makeSound();
	pointers[10]->makeSound();
	for (int i = 0; i < 20; i++)
		delete pointers[i];
}

