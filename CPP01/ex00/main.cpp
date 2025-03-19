#include "Zombie.hpp"

int main()
{
	Zombie zombie1("Zombie_1");
	zombie1.announce();
	Zombie* heap_zombie = newZombie("heap_zombie");
	heap_zombie->announce();
	randomChump("stack_zombie");
	delete heap_zombie;
}
