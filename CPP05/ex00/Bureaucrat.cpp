#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(){
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	std::cout << "constructor was called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
	*this = other;
	std::cout << "copy constructor was called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other)
	{
		// this->_name = other._name;
		this->_grade = other._grade;
	}
	std::cout << "copy assignment operator was called\n";
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade Too Low";
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

std::string Bureaucrat::getName() const{
	return _name;
}

void Bureaucrat::increamentGrade()
{
	_grade--;
	std::cout << "increamenting Grade by 1\n";
	if (_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::deacreamentGrade(){
	_grade++;
	std::cout << "deacreamenting Grade by 1\n";
	if (_grade > 150)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat){
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "\n";
	return out;
}
