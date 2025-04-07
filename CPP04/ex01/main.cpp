#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "Brain.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "===== Basic Polymorphism Test =====" << std::endl;
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << "Animal type: " << animal->getType() << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	std::cout << "\n===== makeSound() Test =====" << std::endl;
	std::cout << "Animal makes sound: ";
	animal->makeSound();
	std::cout << "Dog makes sound: ";
	dog->makeSound();
	std::cout << "Cat makes sound: ";
	cat->makeSound();

	std::cout << "\n===== Deep Copy Test (Dog) =====" << std::endl;
	Dog *originalDog = new Dog();
	// Assume Dog class provides an accessor to its Brain (e.g., getBrain()) for testing.
	// Set an idea in the original dog's Brain.
	originalDog->getBrain()->setIdea(0, "I want to chase my tail");

	// Create a copy using the copy constructor.
	Dog *copyDog = new Dog(*originalDog);

	// Modify the original dog's brain idea.
	originalDog->getBrain()->setIdea(0, "I want to bark at the mailman");

	std::cout << "Original Dog Brain idea[0]: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy Dog Brain idea[0]: " << copyDog->getBrain()->getIdea(0) << std::endl;

	std::cout << "\n===== Array of Animals Test =====" << std::endl;
	const int numAnimals = 6;
	Animal *animals[numAnimals];

	// Fill half with Dogs and half with Cats.
	for (int i = 0; i < numAnimals; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < numAnimals; i++)
	{
		std::cout << "Animal[" << i << "] type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	std::cout << "\n===== Wrong Hierarchy Test =====" << std::endl;
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();
	// const WrongAnimal *wrongDog = new WrongDog(); // if implemented
	std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
	// std::cout << "WrongDog type: " << wrongDog->getType() << std::endl;

	std::cout << "WrongAnimal makes sound: ";
	wrongAnimal->makeSound();
	std::cout << "WrongCat makes sound: ";
	wrongCat->makeSound(); // should output WrongAnimal sound due to non-virtual functions
	std::cout << "WrongDog makes sound: ";
	// wrongDog->makeSound(); // likewise

	std::cout << "\n===== Cleanup =====" << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete originalDog;
	delete copyDog;
	for (int i = 0; i < numAnimals; i++)
	{
		delete animals[i];
	}
	delete wrongAnimal;
	delete wrongCat;
	// delete wrongDog;

	return 0;
}
