#include "Dog.hpp"

Dog::Dog()
{
	this->br = new Brain();
	this->type = "Dog";
	std::cout << "Dog constructor has been called" << std::endl;
}

Dog::~Dog()
{
	delete br;
	std::cout << "Dog destructor has been called" << std::endl;
}

Dog& Dog::operator=(const Dog &dg)
{
	std::cout<<"Dog copy assignment operator  called" << std::endl;
	this->br = new Brain();
	*(this->br) = *(dg.br);
	return *this;
}

Dog::Dog (const Dog &dg)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dg;
}

void Dog::makeSound() const
{
	std::cout << "BARK BARK BARK BARK BARK BARK" << std::endl;
}