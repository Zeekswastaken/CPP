#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string nm, Weapon &weapon);
		~HumanA();
		Weapon &weapon;
		std::string name;
		void attack();
};
#endif