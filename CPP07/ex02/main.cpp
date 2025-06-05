// #include "Array.hpp"

// int main()
// {
// 	try
// 	{
// 		Array<int> a;
// 		std::cout << "Created empty array.\n";

// 		Array<int> b(5);
// 		for (unsigned int i = 0; i < 5; ++i)
// 			b[i] = i * 10;

// 		std::cout << "Array b contents:\n";
// 		for (unsigned int i = 0; i < 5; ++i)
// 			std::cout << "b[" << i << "] = " << b[i] << "\n";
// 		Array<int> c = b;
// 		std::cout << "Array c (copied from b) contents:\n";
// 		for (unsigned int i = 0; i < 5; ++i)
// 			std::cout << "c[" << i << "] = " << c[i] << "\n";
// 		Array<int> d;
// 		d = b;
// 		std::cout << "Array d (assigned from b) contents:\n";
// 		for (unsigned int i = 0; i < 5; ++i)
// 			std::cout << "d[" << i << "] = " << d[i] << "\n";
// 		d[0] = 999;
// 		std::cout << "After modifying d[0], d[0] = " << d[0] << ", b[0] = " << b[0] << "\n";
// 		std::cout << "Accessing out-of-bounds index:\n";
// 		std::cout << b[10] << "\n";
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "Caught exception: " << e.what() << "\n";
// 	}

// 	return 0;
// }

#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
int main(int, char **)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "allooooooooooooooooo\n";
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror; //
	return 0;
}
