#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : hit_points(10), energy_points(10), attack_damage(0){
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << name << " has been destroyed." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0){
	std::cout << "ClapTrap " << name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src){
	*this = src;
	std::cout << "ClapTrap " << name << " has been copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src){
	if (this != &src)
	{
		name = src.name;
		hit_points = src.hit_points;
		energy_points = src.energy_points;
		attack_damage = src.attack_damage;
	}
	return *this;
}


void ClapTrap::attack(const std::string &target){
	if (energy_points > 0 && hit_points > 0)
	{
		energy_points -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target << ", dealing " << attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " has insufficient energy or hit points to attack." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (energy_points > 0 && hit_points > 0)
	{
		hit_points += amount;
		energy_points -= 1;
		std::cout << "ClapTrap " << name << " repairs itself, gaining " << amount << " hit points. Current hit points: " << hit_points << "." << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " cannot repair due to insufficient energy or hit points." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points > 0)
	{
		if ((int)amount >= hit_points)
		{
			hit_points = 0;
			std::cout << "ClapTrap " << name << " takes " << amount << " damage and is now out of hit points!" << std::endl;
		}
		else
		{
			hit_points -= amount;
			std::cout << "ClapTrap " << name << " takes " << amount << " damage. Remaining hit points: " << hit_points << "." << std::endl;
		}
	}
	else
	{
		std::cout << "ClapTrap " << name << " has no hit points left and cannot take more damage." << std::endl;
	}
}

void ClapTrap::SetName(std::string name){
	this->name = name;
}

std::string ClapTrap::GetName(void) const{
	return this->name;
}

void ClapTrap::SetHits(unsigned int hit)
{
	this->hit_points = hit;
}

int ClapTrap::GetHits(void) const{
	return hit_points;
}

void ClapTrap::SetEnergy(unsigned int energy){
	this->energy_points = energy;
}

int ClapTrap::GetEnergy(void) const
{
	return this->energy_points;
}

void ClapTrap::SetAD(unsigned int AD)
{
	this->attack_damage = AD;
}

int ClapTrap::GetAD(void) const
{
	return this->attack_damage;
}
