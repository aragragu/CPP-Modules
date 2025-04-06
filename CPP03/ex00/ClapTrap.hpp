#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string name;
	int			hit_points;
	int			energy_points;
	int			attack_damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& src);
	ClapTrap& operator=(const ClapTrap& src);

	void SetName(std::string name);
	std::string GetName(void) const;
	void SetHits(unsigned int hits);
	int GetHits(void) const;
	void SetEnergy(unsigned int energy);
	int GetEnergy(void) const;
	void SetAD(unsigned int AD);
	int GetAD(void) const;

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();
};



#endif
