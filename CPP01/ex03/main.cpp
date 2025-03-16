#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("sword");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("spiked");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("dildo");
		jim.attack();
	}
	return 0;
}
