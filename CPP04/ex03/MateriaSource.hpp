#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP


#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
private:
	int			index;
	AMateria*	list[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& src);
	MateriaSource& operator=(const MateriaSource& src);
	void learnMateria(AMateria* tool);
	AMateria *createMateria(std::string const &type);
	~MateriaSource();
};


#endif
