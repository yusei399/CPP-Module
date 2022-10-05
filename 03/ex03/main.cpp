#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	turret1("Alex");
	ScavTrap	turret2("Lilith");
	ClapTrap	turret3("Tomma");
	ScavTrap	turret4(turret1);

	turret1.guardGate();
	turret1.attack("Jacob");
	turret1.attack("Avo");
	turret1.attack("Gevorg");
	turret3.attack("Agnesa");
	turret1.takeDamage(10);
	turret1.beRepaired(10);
}