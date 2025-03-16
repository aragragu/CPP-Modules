#ifndef PHONEBOOK_HPP
#define PONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void	add_contact();
	void	search_contact();

private:
	Contact contacts[8];
};


#endif
