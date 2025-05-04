#include "Bureaucrat.hpp"



int main()
{
	try
	{
		Bureaucrat allo("anas", 5);
		allo.increamentGrade();
		allo.increamentGrade();
		allo.increamentGrade();
		allo.increamentGrade();
		std::cout << allo;
		// allo.increamentGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
