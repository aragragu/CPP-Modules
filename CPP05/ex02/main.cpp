// main.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// Seed RNG once for RobotomyRequestForm randomness
	std::srand(static_cast<unsigned>(std::time(NULL)));

	// Create some bureaucrats with varying grades
	Bureaucrat john("John", 50);  // mid‐level
	Bureaucrat alice("Alice", 1); // top‐level
	Bureaucrat bob("Bob", 150);	  // lowest‐level

	// Create one of each form (target names of your choice)
	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("Marvin");
	PresidentialPardonForm pardon("Ford");

	// Print initial state of each form
	std::cout << "\n-- Initial Forms --\n";
	std::cout << shrub << "\n";
	std::cout << robo << "\n";
	std::cout << pardon << "\n";

	// ───── Signing Phase ──────────────────────────────────────────────────────
	std::cout << "\n-- Signing Phase --\n";

	// Shrubbery: requires sign grade 145
	bob.signForm(shrub);  // bob(150) too low → failure
	john.signForm(shrub); // john(50) high enough → success

	// Robotomy: requires sign grade 72
	john.signForm(robo); // john(50) high enough → success

	// Pardon: requires sign grade 25
	john.signForm(pardon);	// john(50) too low → failure
	alice.signForm(pardon); // alice(1) high enough → success

	// ───── Execution Phase ───────────────────────────────────────────────────
	std::cout << "\n-- Execution Phase --\n";

	// Shrubbery: exec grade 137
	bob.executeForm(shrub);	 // not signed & bob low → error
	john.executeForm(shrub); // signed & john(50)>137? (50>137 false) → success

	// Robotomy: exec grade 45
	john.executeForm(robo);	 // signed & john(50)>45? yes → error
	alice.executeForm(robo); // signed & alice(1) OK → *bzz...* + 50/50

	// Pardon: exec grade 5
	alice.executeForm(pardon); // signed & alice(1) OK → pardon message

	std::cout << "\n-- Final Forms State --\n";
	std::cout << shrub << "\n";
	std::cout << robo << "\n";
	std::cout << pardon << "\n";

	return 0;
}
