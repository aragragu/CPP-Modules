#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

	std::cout << "Creating a Cat using default constructor:" << std::endl;
	Cat cat1;
	std::cout << std::endl;

	// Test makeSound function
	std::cout << "Cat makes sound: ";
	cat1.makeSound();
	std::cout << std::endl;

	std::cout << "Creating a Cat using copy constructor:" << std::endl;
	Cat cat2(cat1);
	std::cout << std::endl;

	std::cout << "Assigning cat1 to a new Cat object:" << std::endl;
	Cat cat3;
	cat3 = cat1;
	std::cout << std::endl;

	std::cout << "Polymorphic behavior test:" << std::endl;
	const Animal *animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Cat(cat1);

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "Animal " << i + 1 << " makes sound: ";
		animals[i]->makeSound();
	}
	
	// wat.setType("allo");
	// Clean up
	for (int i = 0; i < 3; ++i)
	{
		delete animals[i];
	}

	return 0;
}
