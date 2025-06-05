#ifndef ITER_H
#define ITER_H

#include <iostream>


template <typename X>
void iter(X* _Arr, size_t lenght, void (*func)(X&)){
	for (size_t i = 0; i < lenght; i++)
	{
		func(_Arr[i]);
	}
}

template <typename Y>
void iter(const Y *_Arr, size_t lenght, void (*func)(const Y &))
{
	for (size_t i = 0; i < lenght; i++)
	{
		func(_Arr[i]);
	}
}

#endif
