#include "Span.hpp"



int main()
{
	try
	{
		Span mySpan(10000);
		std::vector<int> &holder = mySpan.getSpan();
		std::vector<int> allo;
		for (size_t i = 0; i < 5000; i++)
		{
			mySpan.addNumber(i);
		}
		for (size_t i = 5000; i < 10000; i++){
			allo.push_back(i);
		}
		std::cout << "longest span is: " << mySpan.longestSpan() << "\n";
		std::cout << "shortest span is: " << mySpan.shortestSpan() << "\n";
		mySpan.addNumbers(allo.begin(), allo.end());
		for (size_t i = 0; i < mySpan.getSize(); i++)
		{
			std::cout << "holder[" << i << "] = " << holder[i] << "\n";
		}
		std::cout << "shortest span is: " << mySpan.shortestSpan() << "\n";
		std::cout << "longest span is: " << mySpan.longestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
