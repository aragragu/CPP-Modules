#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>


template <typename T>
class Array
{
	private:
	T* array;
	int size;
	public:
	Array();
	Array(unsigned int m);
	Array(const Array& other);
	Array& operator=(const Array& other);
	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
	~Array();
};

#include "Array.tpp"

#endif
