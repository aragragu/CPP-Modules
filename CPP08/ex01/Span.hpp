#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

class Span
{
	private:
		std::vector<int> array;
		unsigned int size;
		unsigned int filled;
		Span(void);
	public :
		Span(unsigned int N);
		Span(Span const &other);
		~Span(void);
		Span &operator = (Span const &other);
		void addNumber(int X);
		std::vector<int>& getSpan();
		int longestSpan();
		int shortestSpan();
		size_t getSize();
		template <typename AnyType>
		void addNumbers(AnyType itBegin, AnyType itEnd){
			unsigned int lenght = std::distance(itBegin, itEnd);
			if ((filled + lenght) > size)
				throw std::runtime_error("array size is not enought");
			for (; itBegin != itEnd; ++itBegin){
				addNumber(*itBegin);
			}
		}
};


#endif

