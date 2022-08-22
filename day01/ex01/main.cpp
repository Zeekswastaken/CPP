#include "Zombie.hpp"

int main()
{
	//Zombie zmb2;
	Zombie *zmb = NULL;
	zmb = zmb->zombieHorde(5, "smelly");
	delete[] (zmb);
}
