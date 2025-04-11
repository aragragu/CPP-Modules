#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>
#include <vector>

int main()
{
	const int size = 4;
	Animal *animals[size];

	// create
	for (int i = 0; i < size; i++)
	{
		std::cout << i << std::endl;
		if (i < size / 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << std::endl;

	// print
	for (int i = 0; i < size; i++)
	{
		std::cout << i << " --> " << "type: " << animals[i]->getType() << ", sound: ";
		animals[i]->makeSound();
	}
	//printing brain;
	Dog* mydog = new Dog;
	for (size_t i = 0; i < 100; i++)
		std::cout << "brain idia[" << i << "] ->> " << mydog->getBrain()->getIdea(i) << std::endl;

	std::cout << std::endl;
	// delete
	for (int i = 0; i < size; i++)
	{
		std::cout << i << std::endl;
		delete animals[i];
	}

	delete mydog;
	return (0);
}
