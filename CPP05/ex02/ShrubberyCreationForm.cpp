#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other){
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &exec) const {
	std::string name = _target + "_shrubbery";
	std::ofstream out_file(name.c_str);
}
