#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
class Animal{
	protected:
		std::string type;
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal& operator=(const Animal &an);
		Animal(const Animal &an);
		virtual void makeSound() const;
		std::string getType() const;
};
#endif