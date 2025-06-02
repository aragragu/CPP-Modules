#ifndef ITER_H
#define ITER_H

#include <iostream>


template <typename T>
void iter(T* _Arr, size_t lenght, void (*func)(T&)){
	for (size_t i = 0; i < lenght; i++)
	{
		func(_Arr[i]);
	}
}

template <typename U>
void iter(const U *_Arr, size_t lenght, void (*func)(const U &))
{
	for (size_t i = 0; i < lenght; i++)
	{
		func(_Arr[i]);
	}
}

#endif
