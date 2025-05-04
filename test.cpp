#include <iostream>
#include <string>

void divide(int a, int b)
{
	if (b == 0)
		throw std::string("Division by zero!");
	std::cout << "Result: " << a / b << std::endl;
}

int main()
{
	try
	{
		divide(10, 0);
	}
	catch (std::string &e)
	{
		std::cout << "Caught an exception: " << e << std::endl;
	}

	return 0;
}
