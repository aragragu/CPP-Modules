#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();

		Animal(const std::string& type);
		Animal(const Animal& src);
		Animal& operator=(const Animal& src);

		void	setType(std::string type);
		std::string getType(void) const;

		virtual void makeSound() const = 0;
};




#endif
