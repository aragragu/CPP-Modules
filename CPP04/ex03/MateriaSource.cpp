#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : index(0)
{
	for (size_t i = 0; i < 4; i++)
		list[i] = NULL;
	std::cout << "MateriaSource: Default constructor invoked;" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		delete list[i];
		list[i] = NULL;
	}
	std::cout << "MateriaSource: Destructor invoked;" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	*this = src;
	std::cout << "MateriaSource: Copy constructor invoked;" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
	if (this != &src)
	{
		for (size_t i = 0; i < 4; i++)
		{
			delete list[i];
			list[i] = NULL;
		}
		for (size_t x = 0; x < 4; x++)
		{
			if (src.list[x])
				this->list[x] = src.list[x]->clone();
		}
		this->index = src.index;
	}
	std::cout << "MateriaSource : Copy assignment operator invoked;" << std::endl;
	return *this;
}

void MateriaSource::learnMateria(AMateria* tool)
{
	if (index == 4)
	{
		delete tool;
		tool = NULL;
		return;
	}
	list[index++] = tool;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t j = 0; j < 4; j++)
	{
		if (list[j] && list[j]->getType() == type)
			return (list[j]->clone());
	}
	return 0;
}
