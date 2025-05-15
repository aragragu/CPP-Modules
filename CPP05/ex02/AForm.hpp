	#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <fstream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;

	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		AForm(std::string name, int signGrade, int executeGrade);

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

		class FormIsNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormCannotBeExecuted : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormAlreadySigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class CouldNotOpenTheFile : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		std::string getName() const;
		int getsignGrade() const;
		int getexecuteGrade() const;
		bool getSign() const;

		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &bureaucrat);
#include "Bureaucrat.hpp"

#endif

