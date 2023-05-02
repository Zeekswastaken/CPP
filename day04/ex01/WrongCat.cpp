#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor has been called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor has been called" << std::endl;
}

WrongCat::WrongCat (const WrongCat &an)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = an.type;
}

WrongCat& WrongCat::operator=(const WrongCat &an)
{
	this->type = an.type;
	std::cout<<"WrongCat copy assignment operator  called" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "MEAOW MEAOW MUFFUKKA" << std::endl;
}