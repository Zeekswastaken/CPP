#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor has been called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor has been called" << std::endl;
}

Cat::Cat (const Cat &an)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = an.type;
}

Cat& Cat::operator=(const Cat &an)
{
	std::cout<<"Cat copy assignment operator  called" << std::endl;
	this->type = an.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MEAOW MEAOW " << std::endl;
}