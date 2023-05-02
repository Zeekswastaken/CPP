#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor has been called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor has been called" << std::endl;
}

Animal::Animal (const Animal &an)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = an.type;
}

Animal& Animal::operator=(const Animal &an)
{
	std::cout<<"Animal copy assignment operator  called" << std::endl;
	this->type = an.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Whatever the hell the sound a random animal makes" << std::endl;
}

std::string Animal::getType() const
{
	return(this->type);
}