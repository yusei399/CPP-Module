#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
	Zombie *zombie_1 = newZombie("zombie_1");
	Zombie *zombie_2 = newZombie("zombie_2");
	Zombie *zombie_3 = newZombie("zombie_3");

	zombie_1->announce();
	zombie_2->announce();
	zombie_3->announce();

	randomChump("sample_1");
	randomChump("sample_2");

	delete zombie_3;
	delete zombie_2;
	delete zombie_1;
}