#ifndef TEST1_HPP
#define TEST1_HPP

#include <iostream>
#include <string>

class Simple
{
	private:
		const std::string name;
		int grade;
	public:
		Simple(std::string& name, int grade);
		// Simple(const Simple &other);
		Simple& operator=(const Simple& src);
		~Simple();
};

#endif
