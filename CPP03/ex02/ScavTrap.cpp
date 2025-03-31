#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "ScavTrap default constructer as been called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	SetHits(100);
	SetEnergy(50);
	SetAD(20);
	std::cout << "ScavTrap " << name << " has been created." << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << GetName() << " has been destroyed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (GetEnergy() > 0 && GetHits() > 0)
	{
		SetEnergy(GetEnergy() - 1);
		std::cout << "ScavTrap " << GetName() << " attacks " << target << ", dealing " << GetAD() << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << GetName() << " has insufficient energy or hit points to attack." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << GetName() << " is now on Gate keeper mode." << std::endl;
}
