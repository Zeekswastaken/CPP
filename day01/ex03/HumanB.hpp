#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string nm);
		~HumanB();
		Weapon *weapon;
		std::string name;
		void attack();
		void	setWeapon(Weapon &wpn);
};
#endif