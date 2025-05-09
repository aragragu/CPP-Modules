#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(150), _executeGrade(150)
{
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
}

Form::~Form()
{
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

Form &Form::operator=(const Form &other)
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

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

const char *Form::FormAlreadySigned::what() const throw()
{
	return "form is already signed";
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSign() const
{
	return _signed;
}

int Form::getsignGrade() const
{
	return _signGrade;
}

int Form::getexecuteGrade() const
{
	return _executeGrade;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", and signedGrade is <" << form.getsignGrade() << "> and executeGrade is <" << form.getexecuteGrade() << "> ";
	if (form.getSign() == true)
		out << "and signed = [TRUE]";
	else
		out << " and signed = [FALSE]";
	return out;
}

void Form::beSigned(Bureaucrat bureaucrat)
{
	// i need to add  another throw in case the form is already signed
	if (this->getSign())
		throw FormAlreadySigned();
	if (this->_signGrade >= bureaucrat.getGrade())
	{
		this->_signed = true;
	}
	else
		throw GradeTooLowException();
}
