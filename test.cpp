#include "test1.hpp"





Simple::Simple(float const p) : pi(p), gaw(10) {
	std::cout << "constaracture called " << std::endl;
}


Simple::~Simple()
{
	std::cout << "destructure called" << std::endl;
}
