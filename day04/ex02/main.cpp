#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
Animal* j = new Dog();
Animal* i = new Cat();
j->makeSound();
delete j;//should not create a leak
delete i;
return 0;
}