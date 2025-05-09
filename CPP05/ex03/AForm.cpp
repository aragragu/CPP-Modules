#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _executeGrade(150)
{
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
		//
		//
		//
	}
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

const char *AForm::FormIsNotSigned::what() const throw()
{
	return "Form is not signed";
}

const char *AForm::FormCannotBeExecuted::what() const throw()
{
	return "grade too low to execute";
}

const char *AForm::FormAlreadySigned::what() const throw()
{
	return "form is already signed";
}

const char *AForm::CouldNotOpenTheFile::what() const throw()
{
	return "could not open the file";
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSign() const
{
	return _signed;
}

int AForm::getsignGrade() const
{
	return _signGrade;
}

int AForm::getexecuteGrade() const
{
	return _executeGrade;
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
	out << Aform.getName() << ", and signedGrade is <" << Aform.getsignGrade() << "> and executeGrade is <" << Aform.getexecuteGrade() << "> ";
	if (Aform.getSign() == true)
		out << "and signed = [TRUE]";
	else
		out << " and signed = [FALSE]";
	return out;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	// i need to add  another throw in case the form is already signed
	if (this->getSign())
		throw FormAlreadySigned();
	if (this->_signGrade >= bureaucrat.getGrade())
		this->_signed = true;
	else
		throw GradeTooLowException();
	// throw GradeTooLowException();
}
