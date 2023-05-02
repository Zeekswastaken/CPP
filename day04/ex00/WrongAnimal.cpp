#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor has been called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal &an)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	type = an.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &an)
{
	type = an.type;
	std::cout<<"WrongAnimal copy assignment operator  called" << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Whatever the hell the sound a random animal makes" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return(this->type);
}