#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " is created" << std::endl;
}

Zombie::~Zombie(){
	std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::annouce(){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
