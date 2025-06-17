#include <vector>
#include <list>
#include <iostream>
#include <string> // For std::string

int main()
{
	// Using std::vector
	std::vector<int> numbers_vec;
	numbers_vec.push_back(10);
	numbers_vec.push_back(20);
	numbers_vec.push_back(30);

	// Declaring an iterator for std::vector<int>
	std::vector<int>::iterator vec_it;

	std::cout << "Vector elements (using iterator):" << std::endl;
	for (vec_it = numbers_vec.begin(); vec_it != numbers_vec.end(); ++vec_it)
	{
		std::cout << *vec_it << " "; // Dereference the iterator to get the value
	}
	std::cout << std::endl;

	// Using std::list
	std::list<std::string> names_list;
	names_list.push_back("Alice");
	names_list.push_back("Bob");
	names_list.push_back("Charlie");

	// Declaring an iterator for std::list<std::string>
	std::list<std::string>::iterator list_it;

	std::cout << "List elements (using iterator):" << std::endl;
	for (list_it = names_list.begin(); list_it != names_list.end(); ++list_it)
	{
		std::cout << *list_it << " "; // Dereference the iterator
	}
	std::cout << std::endl;

	return 0;
}
