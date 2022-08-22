#include "HumanA.hpp"

HumanA::HumanA(std::string nm, Weapon &weapon) : weapon(weapon)
{
	this->name = nm;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
