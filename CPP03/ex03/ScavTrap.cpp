#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap default constructor: [" << name << "] created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap [" << name << "] has been created." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor: [" << name << "] destroyed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "ScavTrap copy constructor: [" << name << "] copied from source." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	std::cout << "ScavTrap copy assignment: [" << name << "] assigned from source." << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (GetEnergy() > 0 && GetHits() > 0)
	{
		SetEnergy(GetEnergy() - 1);
		std::cout << "ScavTrap " << name << " attacks " << target << ", dealing " << GetAD() << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << name << " has insufficient energy or hit points to attack." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now on Gate keeper mode." << std::endl;
}
