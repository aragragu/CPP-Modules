#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(RPN const &copy)
{
	*this = copy;
}

RPN::~RPN(void) {}

RPN const	&RPN::operator = (RPN const &rhs)
{
	(void)rhs;
	return (*this);
}

long RPN::devide(long long a, long long b){
	if (b == 0)
		throw std::runtime_error("Cannot Divide by zero");
	return a / b;
}

long RPN::plus(long long a, long long b){
	return a + b;
}

long RPN::mutiply(long long a, long long b){
	return a * b;
}

long RPN::minus(long long a, long long b){
	return a - b;
}


void RPN::DoOperation(std::string& op, std::stack<long>& numbers){
	if (numbers.size() < 2)
		throw INVALID_NUMBER();
	long long b = numbers.top();
	numbers.pop();
	long long a = numbers.top();
	numbers.pop();
	if (op == "+")
		numbers.push(RPN::plus(a, b));
	else if (op == "-")
		numbers.push(RPN::minus(a, b));
	else if (op == "*")
		numbers.push(RPN::mutiply(a, b));
	else if (op == "/")
		numbers.push(RPN::devide(a, b));
	else
		throw INVALID_OPERATION();
}

const char* RPN::INVALID_NUMBER::what()const throw(){
	return ("Error: invlaid numbers");
}


const char *RPN::INVALID_OPERATION::what() const throw()
{
	return ("Error: invlaid operation");
}


bool RPN::ValidNumber(long& holder, std::string &number){
	for (size_t i = 0; i < number.size(); i++)
	{
		if (!std::isdigit(number[i]))
			return false;
	}
	long checker = std::strtol(number.c_str(), NULL, 10);
	if (checker > INT_MAX || checker < INT_MIN)
		throw std::out_of_range("invalid number, out of int range");
	holder = checker;
	return true;
}
