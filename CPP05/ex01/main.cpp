#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat john("John", 50);
		Bureaucrat alice("Alice", 1);
		Bureaucrat frank("frank", 25);

		Form taxForm("TaxForm", 25, 10); // Requires grade 25 to sign

		std::cout << john << std::endl;
		std::cout << alice << std::endl;
		std::cout << frank << std::endl;
		std::cout << taxForm << std::endl;

		std::cout << "---- John trying to sign the Form ----" << std::endl;
		john.signForm(taxForm); // should throw

		std::cout << "---- Alice trying to sign the Form ----" << std::endl;
		alice.signForm(taxForm); // should succeed

		std::cout << "---- frank trying to sign the Form ----" << std::endl;
		frank.signForm(taxForm); // should succeed

		std::cout << "---- Form Final Status ----" << std::endl;
		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unhandled exception: " << e.what() << std::endl;
	}
	return 0;
}
