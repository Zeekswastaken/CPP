#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
class Dog: virtual public Animal{
	public :
		Dog();
		~Dog();
		Dog(const Dog &dg);
		Dog& operator=(const Dog &dg);
		virtual void makeSound() const;
	private:
		Brain *br;
};
#endif