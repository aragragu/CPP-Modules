#include "MutantStack.hpp"


template <typename AnyType>
MutantStack<AnyType>::MutantStack(void) : std::stack<AnyType>() {}

template <typename AnyType>
MutantStack<AnyType>::MutantStack(MutantStack const &other) : std::stack<AnyType>(other) {
}

template <typename AnyType>
MutantStack<AnyType>::~MutantStack(void) {}

template <typename AnyType>
MutantStack<AnyType> &MutantStack<AnyType>::operator=(MutantStack const &other)
{
	if (this != &other)
		std::stack<AnyType>::operator=(other);
	return *this;
}


template <typename AnyType>
typename MutantStack<AnyType>::MyIterator MutantStack<AnyType>::begin()
{
	return this->c.begin();
}

template <typename AnyType>
typename MutantStack<AnyType>::MyIterator MutantStack<AnyType>::end(){
	return this->c.end();
}

template <typename AnyType>
typename MutantStack<AnyType>::My_Const_Iterator MutantStack<AnyType>::begin() const{
	return this->c.begin();
}

template <typename AnyType>
typename MutantStack<AnyType>::My_Const_Iterator MutantStack<AnyType>::end() const{
	return this->c.end();
}

template <typename AnyType>
typename MutantStack<AnyType>::MyReverseIterator MutantStack<AnyType>::rbegin()
{
	return this->c.rbegin();
}

template <typename AnyType>
typename MutantStack<AnyType>::MyReverseIterator MutantStack<AnyType>::rend(){
	return this->c.rend();
}

template <typename AnyType>
typename MutantStack<AnyType>::MyConstReverseIterator MutantStack<AnyType>::rbegin() const{
	return this->c.rbegin();
}

template <typename AnyType>
typename MutantStack<AnyType>::MyConstReverseIterator MutantStack<AnyType>::rend() const{
	return this->c.rend();
}
