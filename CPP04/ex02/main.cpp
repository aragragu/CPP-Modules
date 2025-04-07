#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Test default constructors
	std::cout << "Creating a Dog using default constructor:" << std::endl;
	Dog dog1;
	std::cout << std::endl;

	std::cout << "Creating a Cat using default constructor:" << std::endl;
	Cat cat1;
	std::cout << std::endl;

	// Test makeSound function
	std::cout << "Dog makes sound: ";
	dog1.makeSound();
	std::cout << "Cat makes sound: ";
	cat1.makeSound();
	std::cout << std::endl;

	// Test copy constructors
	std::cout << "Creating a Dog using copy constructor:" << std::endl;
	Dog dog2(dog1);
	std::cout << std::endl;

	std::cout << "Creating a Cat using copy constructor:" << std::endl;
	Cat cat2(cat1);
	std::cout << std::endl;

	// Test assignment operators
	std::cout << "Assigning dog1 to a new Dog object:" << std::endl;
	Dog dog3;
	dog3 = dog1;
	std::cout << std::endl;

	std::cout << "Assigning cat1 to a new Cat object:" << std::endl;
	Cat cat3;
	cat3 = cat1;
	std::cout << std::endl;

	// Test polymorphism
	std::cout << "Polymorphic behavior test:" << std::endl;
	const Animal *animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog(dog1);
	animals[3] = new Cat(cat1);

	for (int i = 0; i < 4; ++i)
	{
		std::cout << "Animal " << i + 1 << " makes sound: ";
		animals[i]->makeSound();
	}

	// Clean up
	for (int i = 0; i < 4; ++i)
	{
		delete animals[i];
	}

	return 0;
}
