#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon), name(name) {}

HumanA::~HumanA()
{
}

void HumanA::attack(){
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
