#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
class Animal{
	protected:
		std::string type;
	public:
		virtual ~Animal(void);
		Animal& operator=(const Animal &an);
		virtual void makeSound() const = 0;
		std::string getType() const;
};
#endif