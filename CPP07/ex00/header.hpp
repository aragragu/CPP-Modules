#ifndef HEADER_HPP
#define HEADER_HPP


#include <iostream>

template <typename X>
void swap(X &i, X &g)
{
	X x = i;
	i = g;
	g = x;
}

template <typename X>
X min(X i, X g)
{
	return (i > g) ? g : i;
}

template <typename X>
X max(X i, X g)
{
	return (i > g) ? i : g;
}

#endif
