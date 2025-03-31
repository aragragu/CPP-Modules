#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== Testing ClapTrap ===" << std::endl;
	// Test parameterized constructor
	ClapTrap a("Alpha");
	a.attack("Beta");
	a.takeDamage(5);
	a.beRepaired(3);

	std::cout << std::endl;

	// Test copy constructor for ClapTrap
	std::cout << "=== Testing ClapTrap Copy Constructor ===" << std::endl;
	ClapTrap b(a); // Copy constructor
	b.attack("Gamma");
	b.takeDamage(2);
	b.beRepaired(2);

	std::cout << std::endl;

	// Test assignment operator for ClapTrap
	std::cout << "=== Testing ClapTrap Assignment Operator ===" << std::endl;
	ClapTrap c; // Default constructor (if implemented)
	c = a;		// Assignment operator
	c.attack("Delta");

	std::cout << std::endl;

	std::cout << "=== Testing ScavTrap ===" << std::endl;
	// Test parameterized constructor for ScavTrap
	ScavTrap st("Scavvy");
	st.attack("Enemy");
	st.takeDamage(10);
	st.beRepaired(5);
	st.guardGate(); // Unique ScavTrap method

	std::cout << std::endl;

	// Test copy constructor for ScavTrap
	std::cout << "=== Testing ScavTrap Copy Constructor ===" << std::endl;
	ScavTrap stCopy(st); // Copy constructor
	stCopy.attack("Target");
	stCopy.guardGate();

	std::cout << std::endl;

	// Test assignment operator for ScavTrap
	std::cout << "=== Testing ScavTrap Assignment Operator ===" << std::endl;
	ScavTrap stAssign("Temp");
	stAssign = st; // Assignment operator
	stAssign.attack("Another Enemy");
	stAssign.guardGate();


	std::cout << std::endl;
	std::cout << "========destrutos call========" << std::endl;
	return 0;
}
