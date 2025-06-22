#include "main.hpp"

template <typename T>
MyLimitedVector<T>::MyLimitedVector(){

}

template <typename T>
MyLimitedVector<T>::~MyLimitedVector()
{
}

template <typename T>
void MyLimitedVector<T>::push_back(const T &val){
	this->data.push_back(val);
}

template <typename T>
void MyLimitedVector<T>::pop_back(){
	this->data.pop_back();
}

template <typename T>
size_t MyLimitedVector<T>::size(){
	return this->data.size();
}


