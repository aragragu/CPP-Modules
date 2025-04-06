#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), name("default")
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 30;
	std::cout << "DiamondTrap default constructor: [" << name << "] created." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor: [" << name << "] destroyed." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 30;
	std::cout << "DiamondTrap [" << name << "] has been created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	std::cout << "DiamondTrap copy constructor: [" << name << "] copied from source." << std::endl;
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	std::cout << "DiamondTrap copy assignment: [" << name << "] assigned from source." << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
		ScavTrap::operator=(src);
		FragTrap::operator=(src);
		this->name = src.name;
	}
	return *this;
}


void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is: [" << name << "] and ClapTrap name is: [" << ClapTrap::name << "]" << std::endl;
}
