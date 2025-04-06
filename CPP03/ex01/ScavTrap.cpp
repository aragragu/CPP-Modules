#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "ScavTrap default constructor: [" << GetName() << "] created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	SetHits(100);
	SetEnergy(50);
	SetAD(20);
	std::cout << "ScavTrap [" << name << "] has been created." << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor: [" << GetName() << "] destroyed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	*this = src;
	std::cout << "ScavTrap copy constructor: [" << GetName() << "] copied from source." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	std::cout << "ScavTrap copy assignment: [" << GetName() << "] assigned from source." << std::endl;
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
