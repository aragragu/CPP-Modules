#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	// std::cout << "=== Testing ClapTrap ===" << std::endl;

	// ClapTrap a("Alpha");
	// a.attack("Beta");
	// a.takeDamage(5);
	// a.beRepaired(3);

	// std::cout << std::endl;

	// std::cout << "=== Testing ClapTrap Copy Constructor ===" << std::endl;
	// ClapTrap b(a);
	// b.attack("Gamma");
	// b.takeDamage(2);
	// b.beRepaired(2);

	// std::cout << std::endl;

	// std::cout << "=== Testing ClapTrap Assignment Operator ===" << std::endl;
	// ClapTrap c;
	// c = a;
	// c.attack("Delta");

	// std::cout << std::endl;

	std::cout << "=== Testing ScavTrap ===" << std::endl;

	ScavTrap st("beta");
	st.attack("Enemy");
	st.takeDamage(10);
	st.beRepaired(5);
	st.guardGate();

	std::cout << std::endl;

	std::cout << "=== Testing ScavTrap Copy Constructor ===" << std::endl;
	ScavTrap stCopy(st);
	stCopy.attack("Target");
	stCopy.guardGate();

	std::cout << std::endl;

	std::cout << "=== Testing ScavTrap Assignment Operator ===" << std::endl;
	ScavTrap stAssign("Temp");
	stAssign = st;
	stAssign.attack("Another Enemy");
	stAssign.guardGate();

	std::cout << std::endl;
	std::cout << "========destrutos call========" << std::endl;
	return 0;
}
