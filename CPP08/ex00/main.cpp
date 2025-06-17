#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>




int main()
{
	std::vector<int> allo;
	std::deque<int> allo2;
	std::list<int> allo3;



	allo.push_back(10);
	allo.push_back(20);
	allo.push_back(30);

	allo2.push_back(40);
	allo2.push_back(50);
	allo2.push_back(60);

	allo3.push_back(70);
	allo3.push_back(80);
	allo3.push_back(90);

	std::cout << "searshing allo for an accurence of 20:\n";
	try
	{
		easyfind(allo, 20);
		std::cout << "20 was found in the vector\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "searshing allo2 for an accurence of 20:\n";
	try
	{
		easyfind(allo2, 50);
		std::cout << "50 was found in the deque\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "searshing allo3 for an accurence of 20:\n";
	try
	{
		easyfind(allo3, 90);
		std::cout << "90 was found in the list\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
