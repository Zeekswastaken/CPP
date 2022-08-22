#include "HumanB.hpp"

HumanB::HumanB(std::string nm)
{
	this->name = nm;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &wpn)
{
	this->weapon = &wpn;
}