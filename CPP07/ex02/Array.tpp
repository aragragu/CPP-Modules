#include "Array.hpp"

template <typename X>
Array<X>::Array() : array(NULL), size(0)
{
	std::cout << "constructor has been called\n";
}

template <typename X>
Array<X>::Array(unsigned int n) : array(new X[n]), size(n)
{
	std::cout << "Parametries constructor was called\n";
}

template <typename X>
Array<X>::~Array()
{
	delete[] array;
	std::cout << "Destructor has been called\n";
}

template <typename X>
Array<X>::Array(const Array &other)
{
	this->array = new X[other.size];
	for (int i = 0; i < other.size; i++)
	{
		array[i] = other.array[i];
	}
	size = other.size;
	std::cout << "copy constructor was called\n";
}

template <typename X>
Array<X> &Array<X>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] array;
		this->array = new X[other.size];
		for (int i = 0; i < other.size; i++)
		{
			array[i] = other.array[i];
		}
		size = other.size;
	}
	std::cout << "copy assignment operator was called\n";
	return *this;
}

template <typename X>
X &Array<X>::operator[](unsigned int index)
{
	if (index >= static_cast<unsigned int>(size))
		throw std::out_of_range("Index out of Range");
	return array[index];
}

template <typename X>
const X &Array<X>::operator[](unsigned int index) const
{
	if (index >= static_cast<unsigned int>(size))
		throw std::out_of_range("Index out of Range");
	return array[index];
}
