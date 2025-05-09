#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	// if (this->getsignGrade() != 145 || this->getexecuteGrade() != 137)
	// 	throw "";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &exec) const
{
	static int i;
	if (!this->getSign())
		throw FormIsNotSigned();
	if (this->getexecuteGrade() < exec.getGrade())
		throw FormCannotBeExecuted();
	std::cout << "* bzzzz... vrrrr... *\n";
	if ((i % 2) == 0)
		std::cout << _target << " has been robotomized successfully\n";
	else
		std::cout << "The robotomy of " << _target << " failed\n";
}
