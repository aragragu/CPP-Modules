#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	*this = copy;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter& ScalarConverter::operator = (ScalarConverter const &other)
{
	(void)other;
}

bool IsA_Char(const std::string& input){
	if (input.length() == 1 && std::isprint(input[0]))
		return true;
	return false;
}

bool IsAn_Int(const std::string &input){
	size_t i = 0;
	if (input[0] && (input[0] == '-' || input[0] == '+'))
		i++;
	if (i == input.length())
		return false;
	while (input[i])
	{
		if (!std::isdigit(input[i]))
			return false;
		i++;
	}
	if (input.length() > 11)
		return false;
	return true;
}

bool IsA_Float(const std::string &input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return true;
	if (input.length() < 4 || input[input.length() - 1] != 'f')
		return false;
	std::string str = input.substr(0, input.length() - 1);
	if (str.empty() || str[str.length() - 1] == '.')
		return false;
	int i = 0, point = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == (int)str.length())
		return false;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
		{
			if (str[i] == '.')
				point++;
			else
				return false;
		}
		i++;
	}
	return point == 1;
}

bool IsA_Double(const std::string &input)
{
	if (input == "-inf" || input == "+inf" || input == "nan")
		return true;
	if (input.length() < 3 || input[input.length() - 1]== '.')
		return false;

	int i = 0, point = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == (int)input.length())
		return false;
	while (input[i])
	{
		if (!std::isdigit(input[i]))
		{
			if (input[i] == '.')
				point++;
			else
				return false;
		}
		i++;
	}
	return point == 1;
}

void CharConverter(const std::string &string){
	char c = string[0];
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Char: " << c << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(c) << std::endl;
}

void FloatConverter(const std::string &str)
{
	bool special = false;
	double f = std::strtod(str.c_str(), NULL);
	if (std::isinf(f) || std::isnan(f))
		special = true;

	std::cout << std::fixed << std::setprecision(1);
	if (!special)
	{
		if (f < 0 || f > 127)
			std::cout << "char: impossible\n";
		else if (!std::isprint(static_cast<char>(f)))
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: '" << static_cast<char>(f) << "'\n";
		if (f < INT_MIN || f > INT_MAX)
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << static_cast<int>(f) << "\n";
	}
	else
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	std::cout << "float: " << static_cast<float>(f) << "f\n";
	std::cout << "double: " << static_cast<double>(f) << "\n";
}

void DoubleConverter(const std::string &str){
	int special = 0;
	double f = std::strtod(str.c_str(), NULL);
	if (std::isinf(f) || std::isnan(f))
		special = true;

	std::cout << std::fixed << std::setprecision(1);
	if (!special)
	{
		if (f < 0 || f > 127)
			std::cout << "char: impossible\n";
		else if (!std::isprint(static_cast<char>(f)))
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: '" << static_cast<char>(f) << "'\n";
		if (f < INT_MIN || f > INT_MAX)
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << static_cast<int>(f) << "\n";
	}
	else
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	std::cout << "float: " << static_cast<float>(f) << "f\n";
	std::cout << "double: " << f << "\n";
}

void IntConverter(const std::string &str){
	long value = std::strtol(str.c_str(), NULL, 10);

	if(value > INT_MAX || value < INT_MIN)
	{
		std::cout << "char: out of range\n";
		std::cout << "int: out of range\n";
		std::cout << "float: out of range\n";
		std::cout << "double: out of range\n";
		return ;
	}
	if (value < 0 || value > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(value) << "'\n";
	std::cout << "int: " << value << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(value) << "f\n";
	std::cout << "double: " << static_cast<double>(value) << "\n";
}

void ScalarConverter::convert(const std::string& string){

	if (IsA_Char(string))
		CharConverter(string);
	else if (IsA_Float(string))
		FloatConverter(string);
	else if (IsA_Double(string))
		DoubleConverter(string);
	else if (IsAn_Int(string))
		IntConverter(string);
	else
		std::cout << "invalid number\n";
}

