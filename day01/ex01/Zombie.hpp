#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
class Zombie
{
	private:
		std::string name;
		void announce (void);
	public:
		Zombie (void);
		~Zombie (void);
		Zombie* zombieHorde( int N, std::string name );
};
#endif