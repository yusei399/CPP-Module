#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap turret1("BOB");

	turret1.guardGate();
	turret1.attack("Jacob");
	turret1.attack("Avo");
	turret1.attack("Gevorg");
	turret1.whoAmI();
	turret1.beRepaired(10);
	turret1.guardGate();
	turret1.highFivesGuys();
	turret1.takeDamage(10000);
	turret1.attack("hoghoge");
	turret1.attack("hoghoge");
}