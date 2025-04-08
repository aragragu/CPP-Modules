#include <iostream>
#include <string>


// class Animal
// {
// public:
// 	virtual void makeSound() const = 0; // Pure virtual functio
// 	virtual ~Animal() {}
// };

// class Dog : public Animal
// {
// public:
// 	void makeSound() const
// 	{
// 		std::cout << "Woof!" << std::endl;
// 	}
// };

// class Cat : public Animal
// {
// public:
// 	void makeSound() const
// 	{
// 		std::cout << "Meow!" << std::endl;
// 	}
// };

// void animalSound(const Animal &animal)
// {
// 	animal.makeSound();
// }

int main()
{
	// allo->makeSound();
	// animalSound(dog); // Outputs: Woof!
	// animalSound(cat); // Outputs: Meow!
	// delete allo;


	std::string allo[4];
	allo[0] = "0000000";
	allo[1] = "1111111";
	allo[2] = "2222222";
	allo[3] = "3333333";

	int index = 4;
	int idx = 1;

	if (idx < 0 || index == 0 || idx >= index)
		return 0;
	allo[idx] = "empty";
	for (int i = idx; i < 3; i++)
	{
		allo[i] = allo[i + 1];
	}

	allo[3] = "";
	for (size_t x = 0; x < 4; x++)
		std::cout << "allo[" << x << "] = <<" << allo[x] << ">>" << std::endl;

	return 0;
}
