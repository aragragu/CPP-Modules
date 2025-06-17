#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename AnyType>
int easyfind(AnyType &box, int value)
{
	typename AnyType::iterator MyIterator = std::find(box.begin(), box.end(), value);
	if (MyIterator != box.end())
		return *MyIterator;
	else
		throw std::runtime_error("couldn't find the accurence in this container");
}



#endif
