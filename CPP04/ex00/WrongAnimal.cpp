#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("default")
{
	std::cout << "WrongAnimal: Default constructor invoked; type initialized to 'default'." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor invoked; releasing resources for type '[" << type << "]'." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
	std::cout << "WrongAnimal: Parameterized constructor invoked; type set as provided." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal: Copy constructor invoked; duplicating instance with type '[" << type << "]'." << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << "WrongAnimal: Copy assignment operator invoked; updating type to '[" << type << "]'." << std::endl;
	return *this;
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

std::string WrongAnimal::getType(void) const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal is making a sound" << std::endl;
}
