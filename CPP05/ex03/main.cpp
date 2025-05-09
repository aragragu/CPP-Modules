#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 130); // Can sign, but cannot execute Shrubbery (exec grade 137)
		ShrubberyCreationForm form("Garden");

		std::cout << "\nForm before signing:\n"
				  << form << std::endl;

		bob.signForm(form);
		std::cout << "\nForm after signing:\n"
				  << form << std::endl;

		bob.executeForm(form); // Should fail due to low grade

		bob.incrementGrade(); // Now grade = 129 (good enough to execute)

		bob.executeForm(form); // Should succeed now
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
