#include "test1.hpp"





Simple::Simple() : p(0), gaw(00) {
	std::cout << "constaracture called " << std::endl;
}

Simple& Simple::operator=(const Simple& src)
{
	if (this == &src)
		return *this;
	gaw = src.gaw;
	p = src.p;
	return *this;
}

	// Simple::Simple(const Simple &other): p(other.p), gaw(other.gaw){
	// 	std::cout << "copy constructor was called" << std::endl;
	// }

	// void Simple::set_value(int i, int x)
	// {
	// 	this->p = i;
	// 	this->gaw = x;
	// }

	Simple::~Simple()
{
	std::cout << "destructure called" << std::endl;
}

