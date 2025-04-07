#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class WrongDog : public Animal
{
private:
	Brain *brain;
public:
	WrongDog();
	~WrongDog();

	WrongDog(const std::string &type);
	WrongDog(const WrongDog &src);
	WrongDog &operator=(const WrongDog &src);

	void makeSound() const;
	Brain *getBrain(void);
};

#endif
