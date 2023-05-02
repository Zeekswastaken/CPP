#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor has been called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog destructor has been called" << std::endl;
}

Dog::Dog (const Dog &dg)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = dg.type;
}

Dog& Dog::operator=(const Dog &dg)
{
	std::cout<<"Dog copy assignment operator  called" << std::endl;
	this->type = dg.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "BARK BARK BARK BARK BARK BARK " << std::endl;
}