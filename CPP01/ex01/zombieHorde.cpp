#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N > 0)
	{
		Zombie *zombie = new Zombie[N];
		for (int i = 0; i < N; i++)
			zombie[i].set_name(name);
		return zombie;
	}
	else
		return (NULL);
}
