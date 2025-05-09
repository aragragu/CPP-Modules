#include "Intern.hpp"

Intern::Intern(){
	arr[0] = "presidential pardon";
	arr[1] = "robotomy request";
	arr[2] = "shrubbery creation";
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(std::string form_Name, std::string targetName){
	AForm* (Intern::*form_maker[3])(std::string) = {&Intern::makePresident, &Intern::makeRobotomy, &Intern::makeShrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (form_Name == arr[i])
		{
			std::cout << "Intern creates " << form_Name << std::endl;
			return (this->*form_maker[i])(targetName);
		}
	}
	std::cerr << "Form *" << form_Name << "* doesn't exist!" << std::endl;
	return 0;
}

AForm* Intern::makePresident(std::string target){
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomy(std::string target){
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubbery(std::string target){
	return (new ShrubberyCreationForm(target));
}
