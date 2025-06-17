#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>


template <typename X>
class Array
{
	private:
		X* array;
		int size;
	public:
		Array();
		Array(unsigned int m);
		Array(const Array& other);
		Array& operator=(const Array& other);
		X &operator[](unsigned int index);
		const X &operator[](unsigned int index) const;
		~Array();
};

#include "Array.tpp"

#endif
