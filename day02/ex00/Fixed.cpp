#include "Fixed.hpp"

Fixed::Fixed(void)
{
	fixednbr = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixednbr = obj.getRawBits();
}

Fixed& Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fixednbr = fixed.getRawBits();
	return *this;
}
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->fixednbr);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixednbr = raw;
}