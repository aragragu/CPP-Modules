#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog: Default constructor invoked; type set to 'Dog'." << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog: Destructor invoked; cleaning up Dog instance." << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type)
{
	this->type = "Dog";
	brain = new Brain();
	std::cout << "Dog: Parameterized constructor invoked; overriding type to 'Dog'." << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog: Copy constructor invoked; copying Dog-specific data." << std::endl;
	brain = new Brain(*src.brain);
	// *this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		delete brain;
		brain = new Brain(*src.brain);
	}
	std::cout << "Dog: Copy assignment operator invoked; updating Dog instance." << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof." << std::endl;
}

Brain *Dog::getBrain(void)
{
	return brain;
}
