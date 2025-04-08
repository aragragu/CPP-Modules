#include "AMateria.hpp"

AMateria::AMateria() : type(""){
	std::cout << "AMaterie: Default constructor invoked;" << std::endl;
}

AMateria::~AMateria(){
	std::cout << "AMaterie: Destructor invoked;" << std::endl;
}

AMateria::AMateria(const std::string& name) : type(name){
	std::cout << "AMaterie: Parameterized constructor invoked;" << std::endl;
}

AMateria::AMateria(const AMateria &src){
	*this = src;
	std::cout << "AMaterie: Copy constructor invoked;" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << "AMaterie : Copy assignment operator invoked;" << std::endl;
	return *this;
}

const std::string &AMateria::getType() const{
	return this->type;
}

void AMateria::use(ICharacter &target){
	std::cout << "character used [" << type << "]" << "on [" << target.getName() << "]" << std::endl;
}
