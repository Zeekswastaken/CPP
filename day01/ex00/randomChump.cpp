#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
	Zombie	newz;
	newz.name = name;
	newz.announce();
}