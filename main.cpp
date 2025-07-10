// #include "main.hpp"
#include <iostream>
#include <vector>

int main()
{
	int i = 100;
	std::vector<int> jacob;
	int a = 1, b = 1;
	while (b <= i)
	{
		jacob.push_back(b);
		int next = b + 2 * a;
		a = b;
		b = next;
	}

	for (size_t i = 0; i < jacob.size(); i++)
	{
		std::cout << jacob[i] << " ";
	}
	std::cout << "\n";

}
