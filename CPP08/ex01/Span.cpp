#include "Span.hpp"

Span::Span(void) {}


Span::Span(unsigned int N) : array(std::vector<int>(N)), size(N), filled(0){
	// std::cout << "parametrise constructor was called\n";
}

Span::Span(Span const &other) : array(other.array)
{
	this->size = other.size;
	this->filled = other.filled;
	// std::cout << "copy construcotr was called\n";
}

Span::~Span(void) {
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		array = std::vector<int> (other.array);
		size = other.size;
		filled = other.filled;
	}
	// std::cout << "copy assignment operator was called\n";
	return *this;
}

void Span::addNumber(int X){
	if (filled == size)
		throw std::out_of_range("cannot assigne new number. (Reason: no place left)");
	array[filled] = X;
	filled++;
}

std::vector<int>& Span::getSpan(){
	return array;
}

int Span::longestSpan()
{
	if (filled <= 1)
		throw std::runtime_error("array has no number or has only one");
	int small, bigger;
	small = array[0];
	bigger = array[0];
	for (unsigned int i = 0; i < filled; i++)
	{
		if (array[i] < small)
			small = array[i];
		if (array[i] > bigger)
			bigger = array[i];
	}
	return (bigger - small);
}

int Span::shortestSpan(){
	if (filled <= 1)
		throw std::runtime_error("array has no number or has only one");
	std::vector<int> sortedArray = this->array;
	std::sort(sortedArray.begin(), sortedArray.begin() + filled);
	int smallest = sortedArray[1] - sortedArray[0];
	for (size_t i = 0; i < filled - 1; i++)
	{
		int holder = sortedArray[i + 1] - sortedArray[i];
		if (holder < smallest)
			smallest = holder;
	}
	return smallest;
}

size_t Span::getSize(){
	return filled;
}
