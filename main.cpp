#include "main.hpp"


int main()
{

	MyLimitedVector<int> allo;

	allo.push_back(1);
	allo.push_back(2);
	allo.push_back(3);
	allo.push_back(4);
	allo.push_back(5);
	allo.push_back(6);
	allo.push_back(7);
	MyLimitedVector<int>::My_Iterator it = allo.begin();
	for ( ; it != allo.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";

}
