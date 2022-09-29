#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie	*_42yerevan_students = zombieHorde(42, "zombie");
	
	for (size_t i = 0; i < 42; i++)
		_42yerevan_students[i].announce();
	
	delete [] _42yerevan_students;
}
