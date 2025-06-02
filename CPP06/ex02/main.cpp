#include "Base.hpp"


int main()
{

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "Generating object\n\n";
		Base* b = generate();
		std::cout << "indentifing the object pointer type\n\n";
		identify(b);
		std::cout << "indentifing the object reference is type\n\n";
		identify(*b);
		delete b;
		std::cout << "----------------------------------------------\n\n";
	}

}
