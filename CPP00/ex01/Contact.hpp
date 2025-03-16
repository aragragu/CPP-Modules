#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

class Contact
{
	public :
		Contact();
		~Contact();
		int		index;
		void	set_contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
		void	contact_printer();
		std::string	contact_info_getter(int i);
		void	display_contact_info();
	private:
		std::string First_Name;
		std::string Last_Name;
		std::string Nickame;
		std::string Phone_Number;
		std::string Darkest_Secret;
};




#endif
