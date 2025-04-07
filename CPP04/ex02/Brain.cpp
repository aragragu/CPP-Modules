#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor invoked" << std::endl;
	SetIdeas("thoughts");
}

Brain::~Brain()
{
	std::cout << "Brain: Default destructor invoked" << std::endl;
}

Brain::Brain(std::string idea){
	std::cout << "Brain: Parameterized constructor invoked;" << std::endl;
	SetIdeas(idea);
}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain: Copy constructor invoked;" << std::endl;
	*this = src;
}

Brain& Brain::operator=(const Brain& src)
{
	if (this != &src)
	{
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	std::cout << "Brain: Copy assignment operator invoked;" << std::endl;
	return *this;
}


void Brain::SetIdeas(std::string idea)
{
	for (size_t i = 0; i < 100; i++)
		ideas[i] = idea;
}

void Brain::setIdea(int index, std::string idea)
{
	ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	return ideas[index];
}
