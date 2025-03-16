#include "Zombie.hpp"

Zombie *newZombie(std::string name){
	Zombie* h_zombie = new Zombie(name);
	return h_zombie;
}
