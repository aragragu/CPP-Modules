#include "Span.hpp"



int main()
{
	try
	{
		Span mySpan(10);
		int *array;
		mySpan.addNumber(1);
		mySpan.addNumber(2);
		mySpan.addNumber(3);
		mySpan.addNumber(4);
		mySpan.addNumber(5);
		mySpan.addNumber(6);
		mySpan.addNumber(7);
		mySpan.addNumber(8);
		mySpan.addNumber(9);
		mySpan.addNumber(10);
		// mySpan.addNumber(1);
		array = mySpan.getSpan();
		for (int i = 0; i < 10; i++)
		{
			std::cout << "Array[" << i << "] = " << array[i] << "\n";
		}
		std::cout << "longest span is: " << mySpan.longestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
