#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "Animal.hpp"

class WrongDog : public Animal
{
public:
	WrongDog();
	~WrongDog();

	WrongDog(const std::string &type);
	WrongDog(const WrongDog &src);
	WrongDog &operator=(const WrongDog &src);

	void makeSound() const;
};

#endif
