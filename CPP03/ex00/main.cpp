#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("BotA");
	ClapTrap b("BotB");

	a.attack("BotB");
	b.takeDamage(5);

	b.beRepaired(3);
	b.attack("BotA");
	a.takeDamage(7);

	a.beRepaired(4);

	return 0;
}
