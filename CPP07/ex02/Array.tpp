#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), size(0)
{
	std::cout << "constructor has been called\n";
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), size(n)
{
	std::cout << "Parametries constructor was called\n";
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
	std::cout << "Destructor has been called\n";
}

template <typename T>
Array<T>::Array(const Array &other)
{
	this->array = new T[other.size];
	for (int i = 0; i < other.size; i++)
	{
		array[i] = other.array[i];
	}
	size = other.size;
	std::cout << "copy constructor was called\n";
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] array;
		this->array = new T[other.size];
		for (int i = 0; i < other.size; i++)
		{
			array[i] = other.array[i];
		}
		size = other.size;
	}
	std::cout << "copy assignment operator was called\n";
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= static_cast<unsigned int>(size))
		throw std::out_of_range("Index out of Range");
	return array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= static_cast<unsigned int>(size))
		throw std::out_of_range("Index out of Range");
	return array[index];
}
