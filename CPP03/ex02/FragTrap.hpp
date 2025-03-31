#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &src);
	FragTrap &operator=(const FragTrap &src);
	void attack(const std::string &target);
	void highFivesGuys();
	~FragTrap();
};




#endif
