#include "Container.hpp"

Container::Container(std::string S1){
	this->S1 = S1;
}

Container::~Container()
{
}

std::string Container::S2_getter(){
	return S2;
}

void Container::set_string(const char *str, const char *ptr)
{
	std::string file_2;
	std::string replace;
	std::size_t position = 0;
	while ((position = S1.find(str, 0)) != std::string::npos)
	{
		S2 += S1.substr(0, position);
		S2 += ptr;
		S1.erase(0, (position + std::strlen(str)));
	}
	S2 += S1;
}
