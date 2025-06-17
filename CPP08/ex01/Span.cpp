#include "Span.hpp"

Span::Span(void) {}


Span::Span(unsigned int N) : array(new int[N]), size(N), filled(0){
	std::cout << "parametrise constructor was called\n";
}

Span::Span(Span const &copy)
{
	this->array = new int[copy.size];
	for (unsigned int i = 0; i < copy.size; i++){
		this->array[i] = copy.array[i];
	}
	this->size = copy.size;
	this->filled = copy.filled;
	std::cout << "copy construcotr was called\n";
}

Span::~Span(void) {
	delete[] array;
}

Span const	&Span::operator = (Span const &rhs)
{
	if (this != &rhs)
	{
		delete[] array;
		array = new int[rhs.size];
		for (unsigned int i = 0; i < rhs.size; i++){
			array[i] = rhs.array[i];
		}
		size = rhs.size;
		filled = rhs.filled;
	}
	std::cout << "copy assignment operator was called\n";
	return *this;
}

void Span::addNumber(int X){
	if (filled == size)
		throw std::out_of_range("cannot assigne new number. (Reason: no place left)");
	array[filled] = X;
	filled++;
}

int* Span::getSpan(){
	return array;
}

int Span::longestSpan()
{
	if (filled <= 1)
		throw std::runtime_error("array has no number or only one");
	int small, bigger;
	small = array[0];
	bigger = array[0];
	for (unsigned int i = 0; i < size; i++)
	{
		if (array[i] < small)
			small = array[i];
		if (array[i] > bigger)
			bigger = array[i];
	}
	return (bigger - small);
}
