#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
	std::cout << "Cure: Default constructor invoked;" << std::endl;
}

Cure::~Cure(){
	std::cout << "Cure: Destructor invoked;" << std::endl;
}

Cure::Cure(const std::string &type) : AMateria("cure")
{
	(void)type;
	std::cout << "Cure: Parameterized constructor invoked;" << std::endl;
}

Cure::Cure(const Cure& src) : AMateria(src){
	std::cout << "Cure: Copy constructor invoked;" << std::endl;
}

Cure& Cure::operator=(const Cure& src){
	if (this != &src)
		AMateria::operator=(src);
	std::cout << "Cure : Copy assignment operator invoked;" << std::endl;
	return *this;
}

AMateria* Cure::clone() const{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
