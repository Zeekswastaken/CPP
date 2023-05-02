#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor has been called" << std::endl;
}

Brain::~Brain()
{
	//delete this->br;
	std::cout << "Brain destructor has been called" << std::endl;
}

Brain::Brain (const Brain &obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
}

Brain& Brain::operator=(const Brain &an)
{
	std::cout<<"Brain copy assignment operator  called" << std::endl;
	for (int i = 0; i < 100 ; i++)
		this->ideas[i] = an.ideas[i];
	return *this;
}
