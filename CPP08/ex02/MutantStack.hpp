#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>


template <typename AnyType>
class MutantStack : public std::stack<AnyType>
{
	public:
		MutantStack(void);
		MutantStack(MutantStack const &other);
		~MutantStack(void);
		MutantStack &operator=(MutantStack const &other);

		//iterator
		typedef typename std::stack<AnyType>::container_type::iterator MyIterator;
		typedef typename std::stack<AnyType>::container_type::const_iterator My_Const_Iterator;
		typedef typename std::stack<AnyType>::container_type::reverse_iterator MyReverseIterator;
		typedef typename std::stack<AnyType>::container_type::const_reverse_iterator MyConstReverseIterator;


		//iterators methods
		MyIterator begin();
		MyIterator end();

		My_Const_Iterator begin() const;
		My_Const_Iterator end() const;

		MyReverseIterator rbegin();
		MyReverseIterator rend();

		MyConstReverseIterator rbegin() const;
		MyConstReverseIterator rend() const;
	};


#include "MutantStack.tpp"

#endif
