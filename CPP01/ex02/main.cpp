#include <iostream>
#include <string>

int main(){
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "the memory address of the string: [" << &string << "]" << std::endl;
	std::cout << "the memory address of the stringPTR: [" << stringPTR << "]" << std::endl;
	std::cout << "the memory address of the stringREF: [" << &stringREF << "]" << std::endl;

	std::cout << "the value of the string: [" << string << "]" << std::endl;
	std::cout << "the value of the string: [" << *stringPTR << "]" << std::endl;
	std::cout << "the value of the string: [" << stringREF << "]" << std::endl;
}
