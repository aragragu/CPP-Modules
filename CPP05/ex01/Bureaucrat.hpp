#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		std::string getName() const;
		int getGrade() const;

		void IncrementGrade();
		void DecrementGrade();

		void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
