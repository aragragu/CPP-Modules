#include "Zombie.hpp"

Zombie::Zombie() : name("") {
	std::cout << "object is created" << std::endl;
}

Zombie::~Zombie(){
	std::cout << "object is destroyed" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name){
	this->name = name;
}
