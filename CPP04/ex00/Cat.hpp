#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"



class Cat : public Animal
{
	public:
		Cat();
		~Cat();

		Cat(const std::string &type);
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);

		void makeSound() const;
};




#endif
