#include "Contact.hpp"
#include <iomanip>

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::set_contact(std::string first, std::string last, std::string nick, std::string phone,std::string secret)
{
	this->First_Name = first;
	this->Last_Name = last;
	this->Nickame = nick;
	this->Phone_Number = phone;
	this->Darkest_Secret = secret;
}

std::string Contact::contact_info_getter(int i)
{
	if (i == 0)
		return (this->First_Name);
	else if (i == 1)
		return this->Last_Name;
	else if (i == 2)
		return this->Nickame;
	else if (i == 3)
		return this->Phone_Number;
	else
		return this->Darkest_Secret;
}


void	Contact::contact_printer()
{
	std::cout << "First name: " <<this->First_Name << std::endl;
	std::cout << "Last Name: " <<this->Last_Name << std::endl;
	std::cout << "Nick Name: " <<this->Nickame << std::endl;
	std::cout << "Phone Number:" <<this->Phone_Number << std::endl;
	std::cout << "Darkest Secret: " <<this->Darkest_Secret << std::endl;
}

std::string modifie_string(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}


void	Contact::display_contact_info()
{
	std::cout << "|" << std::setw(10) << this->index << "|" << std::setw(10) << modifie_string(this->First_Name) << "|" << std::setw(10) << modifie_string(this->Last_Name) << "|" << std::setw(10) << modifie_string(this->Nickame) << "|" << std::endl;
}
