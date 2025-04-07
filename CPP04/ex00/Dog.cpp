#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog: Default constructor invoked; type set to 'Dog'." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor invoked; cleaning up Dog instance." << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type)
{
	this->type = "Dog";
	std::cout << "Dog: Parameterized constructor invoked; overriding type to 'Dog'." << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog: Copy constructor invoked; copying Dog-specific data." << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
		Animal::operator=(src);
	std::cout << "Dog: Copy assignment operator invoked; updating Dog instance." << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound: Woof Woof." << std::endl;
}
