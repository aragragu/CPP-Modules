#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{

	// Test invalid Bureaucrat construction
	std::cout << "-- Testing Invalid Bureaucrat Creation --\n";
	try
	{
		Bureaucrat invalid("Invalid", 0); // Should throw GradeTooHighException
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
	try
	{
		Bureaucrat invalid("Invalid", 151); // Should throw GradeTooLowException
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}

	// Create bureaucrats
	Bureaucrat alice("Alice", 1); // Highest rank
	Bureaucrat john("John", 50);  // Mid-rank
	Bureaucrat bob("Bob", 150);	  // Lowest rank

	// Create forms
	ShrubberyCreationForm shrub("garden"); // Sign: 145, Exec: 137
	RobotomyRequestForm robo("Marvin");	   // Sign: 72, Exec: 45
	PresidentialPardonForm pardon("Ford"); // Sign: 25, Exec: 5

	// Print initial form states
	std::cout << "\n-- Initial Form States --\n";
	std::cout << shrub << "\n";
	std::cout << robo << "\n";
	std::cout << pardon << "\n";

	// Signing phase
	std::cout << "\n-- Signing Phase --\n";
	bob.signForm(shrub);	// Bob (150) < 145 → fail
	john.signForm(shrub);	// John (50) <= 145 → success
	john.signForm(robo);	// John (50) <= 72 → success
	john.signForm(pardon);	// John (50) < 25 → fail
	alice.signForm(pardon); // Alice (1) <= 25 → success

	// Execution phase
	std::cout << "\n-- Execution Phase --\n";
	bob.executeForm(shrub);	   // Bob (150) < 137 or unsigned → fail
	john.executeForm(shrub);   // John (50) <= 137, signed → success (creates file)
	john.executeForm(robo);	   // John (50) < 45 → fail
	alice.executeForm(robo);   // Alice (1) <= 45, signed → success (random output)
	alice.executeForm(robo);   // Alice (1) <= 45, signed → success (random output)
	alice.executeForm(robo);   // Alice (1) <= 45, signed → success (random output)
	alice.executeForm(robo);   // Alice (1) <= 45, signed → success (random output)
	alice.executeForm(robo);   // Alice (1) <= 45, signed → success (random output)
	alice.executeForm(robo);   // Alice (1) <= 45, signed → success (random output)
	alice.executeForm(pardon); // Alice (1) <= 5, signed → success (pardon message)

	// Test already signed form
	std::cout << "\n-- Test Already Signed --\n";
	john.signForm(shrub); // Should throw FormAlreadySigned

	// Test grade increment/decrement
	std::cout << "\n-- Test Grade Changes --\n";
	try
	{
		alice.incrementGrade(); // Grade 1 → throw GradeTooHighException
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
	try
	{
		bob.decreamentGrade(); // Grade 150 → throw GradeTooLowException
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}

	// Print final form states
	std::cout << "\n-- Final Form States --\n";
	std::cout << shrub << "\n";
	std::cout << robo << "\n";
	std::cout << pardon << "\n";

	return 0;
}
