#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"
#include "Brain.hpp"


class WrongCat : public WrongAnimal
{
private:
	Brain *brain;
public:
	WrongCat();
	~WrongCat();

	WrongCat(const std::string &type);
	WrongCat(const WrongCat &src);
	WrongCat &operator=(const WrongCat &src);

	void makeSound() const;
	Brain *getBrain(void);
};

#endif
