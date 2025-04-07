#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();

	WrongCat(const std::string &type);
	WrongCat(const WrongCat &src);
	WrongCat &operator=(const WrongCat &src);

	void makeSound() const;
};

#endif
