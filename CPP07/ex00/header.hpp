#ifndef HEADER_HPP
#define HEADER_HPP


#include <iostream>

template <typename T>
void swap(T &i, T &g)
{
	T x = i;
	i = g;
	g = x;
}

template <typename T>
T min(T i, T g)
{
	return (i > g) ? g : i;
}

template <typename T>
T max(T i, T g)
{
	return (i > g) ? i : g;
}

#endif
