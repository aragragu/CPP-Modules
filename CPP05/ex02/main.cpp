#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat john("John", 50);
		Bureaucrat alice("Alice", 1);

		AForm tax("Tax", 25, 10); // Requires grade 25 to sign

		std::cout << john << std::endl;
		std::cout << alice << std::endl;
		std::cout << tax << std::endl;

		std::cout << "---- John attempts to sign ----" << std::endl;
		john.signForm(tax); // should throw

		std::cout << "---- Alice attempts to sign ----" << std::endl;
		alice.signForm(tax); // should succeed

		std::cout << "---- Final Form Status ----" << std::endl;
		std::cout << tax << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unhandled exception: " << e.what() << std::endl;
	}

	return 0;
}

