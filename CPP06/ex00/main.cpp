#include "ScalarConverter.hpp"


int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw "invalid arguments\nsyntax = ./ScalarConverter <argument>";
		std::string str(argv[1]);
		ScalarConverter::convert(str);
	}
	catch(const char* e)
	{
		std::cerr << "Error: " << e << '\n';
	}
}
