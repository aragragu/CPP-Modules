#include "Animal.hpp"


Animal::Animal() : type("default")
{
	std::cout << "Animal: Default constructor invoked; type initialized to 'default'." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor invoked; releasing resources for type '["<< type << "]'." << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << "Animal: Parameterized constructor invoked; type set as provided." << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal: Copy constructor invoked; duplicating instance with type '[" << type << "]'." << std::endl;
	*this = src;
}

Animal& Animal::operator=(const Animal& src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << "Animal: Copy assignment operator invoked; updating type to '[" << type << "]'." << std::endl;
	return *this;
}

void Animal::setType(std::string type)
{
	this->type = type;
}

std::string Animal::getType(void) const
{
	return type;
}

