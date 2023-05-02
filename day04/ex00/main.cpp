#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int mai1n()
{
	const Animal* meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const WrongAnimal* x = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	x->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	delete x;
	return 0;
}
int main()
{
	mai1n();
	system("leaks Animal");
}