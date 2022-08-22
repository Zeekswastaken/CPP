#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->Name = name;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
	std::cout << this->Name << " has spawned" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->Name << " has been destroyed" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints > 0)
	{
		this->HitPoints += amount;
		this->EnergyPoints--;
		std::cout << this->Name << "has repared himself" << std::endl;
	}
	else
		std::cout << this->Name << "doesn't have enough Energy Points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{

	this->HitPoints -= amount;
	if (this->HitPoints == 0)
		std::cout << this->Name << "doesn't feel so good" << std::endl;
	else
		std::cout << this->Name << "Has taken some damage" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->EnergyPoints > 0)
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	else
		std::cout <<  this->Name << " doesn't have enough Energy Points" << std::endl;
}