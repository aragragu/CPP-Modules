#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	~Brain();
	Brain(std::string idea);
	Brain(const Brain &src);
	Brain &operator=(const Brain &src);
	void SetIdeas(std::string idea);
	void setIdea(int index, std::string);
	std::string getIdea(int index) const;
};

#endif
