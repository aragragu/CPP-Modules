#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
}

PhoneBook::~PhoneBook(){
}

int		has_only_space(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isspace(str[i]))
			return 1;
	}
	return 0;
}

int		is_a_num(std::string str)
{
	for(int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return 0;
	}
	return 1;
}

std::string	transform_space(std::string str)
{
	std::string new_string;
	bool in_space = false;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
		{
			new_string += str[i];
			in_space = false;
		}
		else
		{
			if (!in_space)
			{
				new_string += ' ';
				in_space = true;
			}
		}
	}
	return new_string;
}


void	PhoneBook::add_contact()
{
	std::string first_name, last_name, nick_name, phone, secret;
	static int i;
	std::cout << "enter first name: ";
	std::getline(std::cin, first_name);
	first_name = transform_space(first_name);
	if (first_name.empty() || !has_only_space(first_name))
	{
		std::cout << "first name is empty or has only spaces" << std::endl;
		return ;
	}
	std::cout << "enter last name: ";
	std::getline(std::cin, last_name);
	last_name = transform_space(last_name);
	if (last_name.empty() || !has_only_space(last_name))
	{
		std::cout << "last name is empty or has only spaces" << std::endl;
		return;
	}
	std::cout << "enter nick name: ";
	std::getline(std::cin, nick_name);
	nick_name = transform_space(nick_name);
	if (nick_name.empty() || !has_only_space(nick_name))
	{
		std::cout << "nick name is empty or has only spaces" << std::endl;
		return;
	}
	std::cout << "enter phone number: ";
	std::getline(std::cin, phone);
	if (phone.empty())
	{
		std::cout << "phone is empty" << std::endl;
		return;
	}
	if (!is_a_num(phone))
	{
		std::cout << "phone must contain only number" << std::endl;
		return;
	}
	if (phone.length() != 10)
	{
		std::cout << "phone must contains 10 digits" << std::endl;
		return;
	}
	std::cout << "enter darkest secret: ";
	std::getline(std::cin, secret);
	secret = transform_space(secret);
	if (secret.empty() || !has_only_space(secret))
	{
		std::cout << "secret is empty or has only spaces" << std::endl;
		return;
	}
	contacts[i % 8].set_contact(first_name, last_name, nick_name, phone, secret);
	contacts[i % 8].index = i % 8;
	std::cout << "Contact has been added sucesfuly" << std::endl;
	i++;
}

void	PhoneBook::search_contact()
{
	int contact_num = 0;
	std::string	index;

	for(int i = 0; i < 8; i++)
	{
		if (!contacts[i].contact_info_getter(0).empty())
			contact_num++;
	}
	if (!contact_num)
	{
		std::cout << "no available contact" << std::endl;
		return ;
	}
	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		if (!contacts[i].contact_info_getter(0).empty())
		{
			contacts[i].display_contact_info();
		}
	}
	std::cout << "enter contact index: ";
	std::getline(std::cin, index);
	if (!index.empty())
	{
		int num = atoi(index.c_str());
		if ((is_a_num(index) && (num >= 0 && num <= (contact_num - 1))))
			contacts[num].contact_printer();
		else
			std::cout << "index is not valid" << std::endl;
	}
	else
		std::cout << "index is not valid" << std::endl;
}
