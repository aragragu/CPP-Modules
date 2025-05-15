#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{

	std::cout << "-- Testing Invalid Bureaucrat Creation --\n";
	try
	{
		Bureaucrat invalid("Invalid", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}
	try
	{
		Bureaucrat invalid("Invalid", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}

	Bureaucrat alice("Alice", 1);
	Bureaucrat john("John", 50);
	Bureaucrat bob("Bob", 150);

	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robo("Marvin");
	PresidentialPardonForm pardon("Ford");

	std::cout << "\n-- Initial Form States --\n";
	std::cout << shrub << "\n";
	std::cout << robo << "\n";
	std::cout << pardon << "\n";

	std::cout << "\n-- Signing Phase --\n";
	bob.signForm(shrub);
	john.signForm(shrub);
	john.signForm(robo);
	john.signForm(pardon);
	alice.signForm(pardon);

	std::cout << "\n-- Execution Phase --\n";
	bob.executeForm(shrub);
	john.executeForm(shrub);
	std::cout << "*********************************\n";
	john.executeForm(robo);
	std::cout << "---------------------------------\n";
	alice.executeForm(robo);
	std::cout << "---------------------------------\n";
	alice.executeForm(robo);
	std::cout << "---------------------------------\n";
	alice.executeForm(robo);
	std::cout << "---------------------------------\n";
	alice.executeForm(robo);
	std::cout << "---------------------------------\n";
	alice.executeForm(robo);
	std::cout << "---------------------------------\n";
	alice.executeForm(robo);
	std::cout << "*********************************\n";
	alice.executeForm(pardon);

	std::cout << "\n-- Test Already Signed --\n";
	john.signForm(shrub);

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

	std::cout << "\n-- Final Form States --\n";
	std::cout << shrub << "\n";
	std::cout << robo << "\n";
	std::cout << pardon << "\n";

	return 0;
}
