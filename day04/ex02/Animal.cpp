#include "Animal.hpp"

Animal::~Animal()
{
	std::cout << "Animal destructor has been called" << std::endl;
}

Animal& Animal::operator=(const Animal &an)
{
	this->type = an.type;
	std::cout<<"Animal copy assignment operator  called" << std::endl;
	return *this;
}

std::string Animal::getType() const
{
	return(this->type);
}