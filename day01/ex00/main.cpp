#include "Zombie.hpp"

int main()
{
	Zombie newz;
	Zombie	*zmb = NULL;
	zmb = newz.newZombie("keke");
	delete(zmb);
}