#include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
{
	std::cout << "Ice: Default constructor invoked;" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice: Destructor invoked;" << std::endl;
}

Ice::Ice(std::string &type) : AMateria("Ice")
{
	(void)type;
	std::cout << "Ice: Parameterized constructor invoked;" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	std::cout << "Ice: Copy constructor invoked;" << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
	if (this != &src)
		AMateria::operator=(src);
	std::cout << "Ice : Copy assignment operator invoked;" << std::endl;
	return *this;
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}
