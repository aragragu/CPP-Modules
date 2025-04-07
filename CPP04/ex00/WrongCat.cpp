#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat: Default constructor invoked; type set to 'WrongCat'." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor invoked; cleaning up WrongCat instance." << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
	this->type = "WrongCat";
	std::cout << "WrongCat: Parameterized constructor invoked; overriding type to 'WrongCat'." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << "WrongCat: Copy constructor invoked; duplicating WrongCat instance." << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
		WrongAnimal::operator=(src);
	std::cout << "WrongCat: Copy assignment operator invoked; updating WrongCat instance." << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound: Meow Meow." << std::endl;
}
