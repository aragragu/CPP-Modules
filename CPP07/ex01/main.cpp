#include "iter.hpp"



void modifie_index(std::string& number){
	number = "/////" + number  + "\\\\\\\\\\";
	std::cout << "number: " << number << "\n";
}

void modifie_index(const std::string &number)
{
	std::cout << "number: " << number << "\n";
}

int main()
{
	const std::string arr[5] = {"11111111", "22222222", "33333333", "44444444", "55555555"};
	// std::string arr[5] = {"11111111", "22222222", "33333333", "44444444", "55555555"};

	iter<std::string>(arr, 5, modifie_index);
	iter<std::string>(arr, 5, modifie_index);
	iter<std::string>(arr, 5, modifie_index);
}
