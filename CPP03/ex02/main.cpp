#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "=== Testing ClapTrap ===" << std::endl;
	ClapTrap c1("ClapOne");
	c1.attack("Target1");
	c1.takeDamage(3);
	c1.beRepaired(2);

	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	ScavTrap s1("ScavOne");
	s1.attack("Target2");
	s1.takeDamage(10);
	s1.beRepaired(5);
	s1.guardGate();

	std::cout << "\n=== Testing FragTrap ===" << std::endl;
	FragTrap f1("FragOne");
	f1.attack("Target3");
	f1.takeDamage(20);
	f1.beRepaired(15);
	f1.highFivesGuys(); 

	std::cout << "\n=== Testing Copy Constructor for FragTrap ===" << std::endl;
	FragTrap f2(f1);
	f2.attack("Target4");
	f2.highFivesGuys();

	std::cout << "\n=== Testing Copy Assignment for FragTrap ===" << std::endl;
	FragTrap f3("Temp");
	f3 = f1;
	f3.attack("Target5");
	f3.highFivesGuys();

	std::cout << "\n=== Destructor Calls ===" << std::endl;
	return 0;
}
