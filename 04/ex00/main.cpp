#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main()
{
	Animal	*meta = new Animal;
	Animal	*dog = new Dog;
	Animal	*cat = new Cat;
	std::cout << "meta's type: " << meta->getType() << std::endl;
	std::cout << "dog's type: " << dog->getType() << std::endl;
	std::cout << "cat's type: " << cat->getType() << std::endl;
	cat->makeSound(); 
	dog->makeSound();
	meta->makeSound();

	cat->operator=(*dog);
	std::cout << "After `cat = dog;`:" << std::endl;
	std::cout << "dog's type: " << dog->getType() << std::endl;
	std::cout << "cat's type: " << cat->getType() << std::endl;
	Animal *k = new Cat(*static_cast<Cat*>(cat));
	k->makeSound();
	std::cout << "k's type: " << k->getType() << std::endl;
	delete meta;
	delete dog;
	delete cat;
	delete k;

	std::cout << "Wrong Animal testing." << std::endl;
	WrongAnimal	*wrong = new WrongAnimal;
	WrongAnimal	*evil_cat = new WrongCat;

	std::cout << "evil_cat's type: " << evil_cat->getType() << std::endl;
	wrong->makeSound();
	evil_cat->makeSound();
	delete wrong;
	delete evil_cat;
}