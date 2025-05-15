#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat alice("Alice", 1);
	Bureaucrat john("John", 50);
	Bureaucrat bob("Bob", 150);
	Intern intern;
	std::cout << "-- Testing Invalid Bureaucrat Creation --\n";
	try
	{
		Bureaucrat no_use("no_use", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
	std::cout << "\n-- Testing Intern Form Creation --\n";
	AForm *shrub = intern.makeForm("shrubbery creation", "garden");
	AForm *robo = intern.makeForm("robotomy request", "Marvin");
	AForm *pardon = intern.makeForm("presidential pardon", "Ford");
	AForm *no_use = intern.makeForm("no_use form", "nowhere");
	std::cout << "\n-- Initial Form States --\n";
	if (shrub)
		std::cout << *shrub << "\n";
	if (robo)
		std::cout << *robo << "\n";
	if (pardon)
		std::cout << *pardon << "\n";
	std::cout << "\n-- Signing Phase --\n";
	if (shrub)
	{
		bob.signForm(*shrub);
		john.signForm(*shrub);
	}
	if (robo)
	{
		john.signForm(*robo);
	}
	if (pardon)
	{
		john.signForm(*pardon);
		alice.signForm(*pardon);
	}
	std::cout << "\n-- Execution Phase --\n";
	if (shrub)
	{
		bob.executeForm(*shrub);
		john.executeForm(*shrub);
	}
	if (robo)
	{
		john.executeForm(*robo);
		alice.executeForm(*robo);
	}
	if (pardon)
	{
		alice.executeForm(*pardon);
	}
	std::cout << "\n-- Test Already Signed --\n";
	if (shrub)
	{
		john.signForm(*shrub);
	}
	std::cout << "\n-- Test Grade Changes --\n";
	try
	{
		alice.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
	try
	{
		bob.decreamentGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
	delete shrub;
	delete robo;
	delete pardon;
	delete no_use;

	return 0;
}
