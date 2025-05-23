#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
	// *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &exec) const
{
	if (!this->getSign())
		throw FormIsNotSigned();
	if (this->getexecuteGrade() < exec.getGrade())
		throw FormCannotBeExecuted();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
