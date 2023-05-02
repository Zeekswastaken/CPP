#include "Span.hpp"

Span::Span()
{
	this->N = 0;
	std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int n) : vect(0)
{
	this->N = n;
	std::cout << "Parameterized constructor called" << std::endl;
}

Span::~Span()
{
	std::cout << "Deconstructor called" << std::endl;
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span& Span::operator=(const Span &obj)
{
	std::cout << "Overloading operator called";
	this->N = obj.N;
	this->vect = obj.vect;
	return (*this);
}

void Span::addNumber(int num)
{
	if (this->N > this->vect.size())
		vect.push_back(num);
	else
		throw std::out_of_range("The number that you wanted to add is out of range");
}

int Span::shortestSpan()
{
	if (this->N <= 1)
		throw std::logic_error("Not enough numbers to generate the shortest span");
	std::vector <int> temp_vect = vect;
	std::vector<int>::iterator it;
	sort(temp_vect.begin(), temp_vect.end());
	int res = *(temp_vect.begin() + 1) - *(temp_vect.begin());
	if (this->N == 2)
		return (res);
	for(it = temp_vect.begin() + 1; it != temp_vect.end() - 1 && res != 0; it++)
	{
		if (*(it + 1) - *(it) < res)
			res = *(it + 1) - *(it);
	}
	return (res);
}

int Span::longestSpan()
{
	if (this->N <= 1)
		throw std::logic_error("Not enough numbers to generate the longest span");
	std::vector <int> temp_vect = vect;
	sort(temp_vect.begin(), temp_vect.end());
	int i = *(temp_vect.end() - 1) - *(temp_vect.begin());
	return (i);
}

void Span::AddMore(int *begin, int *last)
{
	for (int *ptr = begin; ptr != last ; ptr++)
	{
		this->addNumber(*(ptr));
	}
}