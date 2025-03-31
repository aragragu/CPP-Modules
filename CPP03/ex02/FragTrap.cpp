#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructer as been called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " has been created." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been destroyed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -= 1;
		std::cout << "FragTrap " << name << " attacks " << target << ", dealing " << attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << name << " has insufficient energy or hit points to attack." << std::endl;
}


void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " is asking you for a hight five." << std::endl;
}
