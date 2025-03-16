#include "PhoneBook.hpp"

int main()
{
	PhoneBook my_book;
	std::string command;

	while (1)
	{
		std::cout << "enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nEOF detected (Ctrl + D). Exiting..." << std::endl;
			break;
		}
		if (command == "ADD")
		{
			my_book.add_contact();
		}
		else if (command == "SEARCH")
		{
			my_book.search_contact();
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "invalid command" << std::endl;
	}
}
