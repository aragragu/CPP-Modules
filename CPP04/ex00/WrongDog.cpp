#include "WrongDog.hpp"

WrongDog::WrongDog() : Animal()
{
	type = "WrongDog";
	std::cout << "WrongDog: Default constructor invoked; type set to 'WrongDog'." << std::endl;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog: Destructor invoked; cleaning up WrongDog instance." << std::endl;
}

WrongDog::WrongDog(const std::string &type) : Animal(type)
{
	this->type = "WrongDog";
	std::cout << "WrongDog: Parameterized constructor invoked; overriding type to 'WrongDog'." << std::endl;
}

WrongDog::WrongDog(const WrongDog &src) : Animal(src)
{
	std::cout << "WrongDog: Copy constructor invoked; copying WrongDog-specific data." << std::endl;
	*this = src;
}

WrongDog &WrongDog::operator=(const WrongDog &src)
{
	if (this != &src)
		Animal::operator=(src);
	std::cout << "WrongDog: Copy assignment operator invoked; updating WrongDog instance." << std::endl;
	return *this;
}

void WrongDog::makeSound() const
{
	std::cout << "WrongDog sound: Woof Woof." << std::endl;
}
