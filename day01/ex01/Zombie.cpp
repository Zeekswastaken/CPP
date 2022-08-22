#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie spawned" << std::endl;
}
Zombie::~Zombie(void)
{
	std::cout << "Zombie got destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}