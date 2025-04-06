#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap default constructor: [" << name << "] created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap [" << name << "] has been created." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor: [" << name << "] destroyed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "FragTrap copy constructor: [" << name << "] copied from source." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	std::cout << "FragTrap copy assignment: [" << name << "] assigned from source." << std::endl;
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
