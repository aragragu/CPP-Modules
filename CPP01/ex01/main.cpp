#include "Zombie.hpp"

int main()
{
	int i = 10;
	Zombie* zombie = zombieHorde(i, "ZOMBIE");
	if (zombie)
	{
		for (int x = 0; x < i; x++)
			zombie[x].announce();
		delete[] zombie;
	}
	else
		std::cout << "failed to allocate space for objects" << std::endl;
}
