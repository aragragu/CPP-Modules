#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stdexcept>


class Span
{
	private:
		int* array;
		unsigned int size;
		unsigned int filled;
		Span(void);
	public :
		Span(unsigned int N);
		Span(Span const &copy);
		~Span(void);
		Span const &operator = (Span const &rhs);
		void addNumber(int X);
		int* getSpan();
		int longestSpan();
};

#endif

