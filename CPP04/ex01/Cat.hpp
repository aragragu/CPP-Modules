#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{
	private:
		Brain* brain;
	public:
		Cat();
		~Cat();

		Cat(const std::string &type);
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);

		void makeSound() const;
		Brain *getBrain(void);
};




#endif
