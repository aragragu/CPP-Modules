#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat: Default constructor invoked; type set to 'Cat'." << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat: Destructor invoked; cleaning up Cat instance." << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type)
{
	this->type = "Cat";
	brain = new Brain();
	std::cout << "Cat: Parameterized constructor invoked; overriding type to 'Cat'." << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat: Copy constructor invoked; duplicating Cat instance." << std::endl;
	brain = new Brain(*src.brain);
	// *this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		delete brain;
		brain = new Brain(*src.brain);
	}
	std::cout << "Cat: Copy assignment operator invoked; updating Cat instance." << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound: Meow Meow." << std::endl;
}

Brain *Cat::getBrain(void)
{
	return brain;
}
