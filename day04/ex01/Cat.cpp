#include "Cat.hpp"

Cat::Cat()
{
	this->br = new Brain();
	this->type = "Cat";
	std::cout << "Cat constructor has been called" << std::endl;
}

Cat::~Cat()
{
	delete this->br;
	std::cout << "Cat destructor has been called" << std::endl;
}

Cat& Cat::operator=(const Cat &an)
{
	std::cout<<"Cat copy assignment operator  called" << std::endl;
	this->br = new Brain();
	*(this->br) = *(an.br);
	return *this;
}

Cat::Cat (const Cat &an)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = an;
}

void Cat::makeSound() const
{
	std::cout << "MEAOW MEAOW" << std::endl;
}