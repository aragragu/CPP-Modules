#ifndef TEST1_HPP
#define TEST1_HPP

#include <iostream>

class Simple
{
public:
	int p;
	int gaw;
	Simple();
	// Simple(const Simple &other);
	Simple& operator=(const Simple& src);
	~Simple();
};

#endif
