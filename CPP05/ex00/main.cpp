#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat allo("anas", 5);
		allo.IncrementGrade();
		allo.IncrementGrade();
		allo.IncrementGrade();
		allo.IncrementGrade();
		std::cout << allo;
		allo.IncrementGrade();
		allo.IncrementGrade();
		allo.IncrementGrade();

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
