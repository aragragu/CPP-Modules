#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {}

Base* generate(void)
{
	std::srand(clock());
	int number = std::rand();
	if (number % 3 == 0)
		return new A;
	else if (number % 3 == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "Base *p is a class type: A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Base *p is a class type: B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Base *p is a class type: C\n";
	else
		std::cout << "Base *p is a class type: Base\n";
}

void identify(Base& p){
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "Base& p is a class type: A\n";
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B b = dynamic_cast<B &>(p);
		std::cout << "Base& p is a class type: B\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C c = dynamic_cast<C &>(p);
		std::cout << "Base& p is a class type: C\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}
	std::cout << "Base& p is a class type: Base\n";
}
