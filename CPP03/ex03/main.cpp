#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dt("Diamond");

	dt.whoAmI();
	dt.attack("enemy");

	dt.takeDamage(30);
	dt.beRepaired(20);

	return 0;
}
