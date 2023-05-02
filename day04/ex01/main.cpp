#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int na1in(){
	//const Dog* j = new Dog();
	//const Animal* i = new Cat();
	//j->br->ideas[0] = "Hello Mark";
	//const Dog *x = j;
	//delete j;//should not create a leak
	//std::cout << "TYPE IS ===" << x->br->ideas[0] << std::endl;
	//delete i;

	// Animal *an[100];
	// for (int i = 0 ; i < 100; i++)
	// {
	// 	if (i <= 50)
	// 		an[i] = new Dog();
	// 	else
	// 		an[i] = new Cat();
	// 	std::cout << "TYPE = " << an[i]->getType();
	// }

	// for (int i = 0 ; i < 100; i++)
	// 	delete an[i];

	// 	Animal *an[4];
	// for (int i = 0 ; i < 4; i++)
	// {
	// 	if (i < 2)
	// 		an[i] = new Dog();
	// 	else
	// 	an[i] = new Cat();
	// 	std::cout << "TYPE = " << an[i]->getType() << std::endl;
	// }
	// Cat d;
	// for(int i = 0 ; i < 100 ; i++)
	// {
	// 	d.br->ideas[i] = "cat 1";
	// }
	// Cat c(d);
	// for(int i = 0 ; i < 100 ; i++)
	// {
	// 	d.br->ideas[i] = "cat 2";
	// }
	// for(int i = 0 ; i < 100 ; i++)
	// {
	// 	std::cout << c.br->ideas[i] << std::endl;
	// }
	// std::cout << "----------------" << std::endl;
	// for(int i = 0 ; i < 100 ; i++)
	// {
	// 	std::cout << d.br->ideas[i] << std::endl;
	// }
	// for(int i = 0; i < 100; i++)
	// 	d.br->ideas[i] = "HELLO";
	// for(int i = 0; i < 100; i++)
	// 	std::cout << c.br->ideas[i] << std::endl;
	// for (int i = 0 ; i < 4; i++)
	// 	delete an[i];
	return 0;
}

int main()
{
	na1in();
	system("leaks Animal");
}