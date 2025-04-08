#include "Character.hpp"

Character::Character() : index(0), name(""){
	for (size_t i = 0; i < 4; i++)
		materia[i] = NULL;
	std::cout << "Character: Default constructor invoked;" << std::endl;
}

Character::~Character(){
	std::cout << "Character: Destructor invoked;" << std::endl;
}


Character::Character(std::string& name): index(0), name(name){
	for (size_t i = 0; i < 4; i++)
		materia[i] = NULL;
	std::cout << "Character: Parameterized constructor invoked;" << std::endl;
}


Character::Character(const Character& src)
{
	*this = src;
}

Character& Character::operator=(const Character& src)
{
	if (this != &src)
	{
		delete[] materia;
		for (size_t i = 0; i < 4; i++)
			materia[i] = NULL;
		this->index = src.index;
		this->name = src.name;
		for (size_t i = 0; i < 4; i++)
		{
			if (src.materia[i])
				this->materia[i] = src.materia[i]->clone();
		}
	}
	std::cout << "Character : Copy assignment operator invoked;" << std::endl;
	return *this;
}

void Character::equip(AMateria* m)
{
	if (!m || index > 3)
		return ;
	materia[index++] = m;
}



void Character::unequip(int idx)
{
	if (idx < 0 || index == 0 || idx >= index)
		return;
	materia[idx] = NULL;
	for (int i = idx; i < 3; i++)
		materia[i] = materia[i + 1];
	materia[3] = NULL;
	index -= 1;
}

void Character::use(int idx, ICharacter& target)
{
	materia[idx]->use(target);
}


const std::string& Character::getName() const{
	return name;
}
