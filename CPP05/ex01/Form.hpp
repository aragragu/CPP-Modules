#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;

	public:
		Form();
		~Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);

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

		class FormAlreadySigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		std::string getName() const;
		int getsignGrade() const;
		int getexecuteGrade() const;
		bool getSign() const;

		void beSigned(Bureaucrat& bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &bureaucrat);

#endif
