#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	Zombie *zmb = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		zmb[i].name = name;
		zmb[i].announce();
		i++;
	}
	return (zmb);
}