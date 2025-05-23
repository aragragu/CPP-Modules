#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
	// *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &exec) const
{
	if (!this->getSign())
		throw FormIsNotSigned();
	if (this->getexecuteGrade() < exec.getGrade())
		throw FormCannotBeExecuted();
	std::string name = _target + "_shrubbery";
	std::ofstream out_file(name.c_str());
	if (out_file.is_open())
	{
		out_file << "       v .   ._, |_  .,\n";
		out_file << "    `-._\\/  .  \\ /    |/_\n";
		out_file << "        \\\\  _\\, y | \\//\n";
		out_file << "  _\\_.___\\\\, \\\\/ -.\\||\n";
		out_file << "    `7-,--.`._||  / / ,\n";
		out_file << "    /'     `-. `./ / |/_.'\n";
		out_file << "              |    |//\n";
		out_file << "              |_    /\n";
		out_file << "              |-   |\n";
		out_file << "              |   =|\n";
		out_file << "              |    |\n";
		out_file << "-----------/ ,  . \\--------._\n";
		out_file.close();
	}
	else
		throw CouldNotOpenTheFile();
}
