#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

class Container
{
private:
	std::string S1;
	std::string S2;
public:
	Container(std::string S1);
	~Container();
	std::string S2_getter();
	void set_string(const char *str, const char *ptr);
};





#endif
