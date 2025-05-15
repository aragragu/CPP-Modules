#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
	private:
		std::string arr[3];
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);


		AForm* makeForm(std::string formName, std::string targetName);
		AForm* makePresident(std::string target);
		AForm* makeRobotomy(std::string Target);
		AForm* makeShrubbery(std::string target);
};







#endif
