#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
	// *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &exec) const
{
	if (!this->getSign())
		throw FormIsNotSigned();
	if (this->getexecuteGrade() < exec.getGrade())
		throw FormCannotBeExecuted();
	std::cout << "* bzzzz... vrrrr... *\n";
	if ((std::rand() % 2) == 0)
		std::cout << _target << " has been robotomized successfully\n";
	else
		std::cout << "The robotomy of " << _target << " failed\n";
}
