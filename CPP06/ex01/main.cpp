#include "Serializer.hpp"


int main()
{
	Data allo;
	allo.i = 1;
	std::cout << "Data allo address is : " << &allo << "\n";
	uintptr_t yo = Serializer::serialize(&allo);
	std::cout << "uintptr_t address is : " << &yo << "\n";
	Data *second = Serializer::deserialize(yo);
	std::cout << "Data *second address is : " << second << "\n";
}
