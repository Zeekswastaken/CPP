#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string name )
{
	Zombie *newz = new Zombie;

	newz->name = name;
	newz->announce();
	return (newz);
}