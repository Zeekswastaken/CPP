#include "Fixed.hpp"

int power(int number, const int pow)
{
	int i = 0;
	int res = 1;
	while (i < pow)
	{
		res*=number;
		i++;
	}
	return (res);
}

Fixed::Fixed(void)
{
	fixednbr = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
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

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixednbr = nbr << this->fixedfract;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixednbr = roundf(nb * power(2, this->fixedfract));
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixednbr / (float)(1 << this->fixedfract));

}

int Fixed::toInt(void) const
{
	return(this->fixednbr >> this->fixedfract);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return (os);
}