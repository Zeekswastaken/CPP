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

bool Fixed::operator==(const Fixed &fix) const
{
	return(this->getRawBits() == fix.getRawBits());
}

bool Fixed::operator>(const Fixed &fix) const
{
	if (this->getRawBits() > fix.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<(const Fixed &fix) const
{
	if (this->getRawBits() < fix.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(Fixed const &fix) const
{
	if (this->getRawBits() >= fix.getRawBits())
		return (true);
	else
		return(false);
}

bool Fixed::operator<=(Fixed const &fix) const
{
	if (this->getRawBits() <= fix.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(Fixed const &fix) const
{
	if (this->getRawBits() != fix.getRawBits())
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(Fixed const &fix) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() + fix.getRawBits());
	return (res);
}

Fixed Fixed::operator-(Fixed const &fix) const
{
	Fixed res;
	res.setRawBits(this->getRawBits() - fix.getRawBits());
	return (res);
}

Fixed Fixed::operator*(Fixed const &fix) const
{
	Fixed res(this->toFloat() * fix.toFloat());
	return (res);
}

Fixed Fixed::operator/(Fixed const &fix) const
{
	Fixed res(this->toFloat() / fix.toFloat());
	return (res);
}

Fixed Fixed::operator++(void)
{
	Fixed temp;
	temp.fixednbr = ++fixednbr;
	return (temp);
}

Fixed Fixed::operator++(int)
{
	Fixed temp;
	temp.fixednbr = fixednbr++;
	return (temp);
}

Fixed Fixed::operator--(void)
{
	Fixed temp;
	temp.fixednbr = --fixednbr;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp;
	temp.fixednbr = fixednbr--;
	return (temp);
}

Fixed& Fixed::min(Fixed &fix, Fixed &fx)
{
	if (fix < fx)
		return (fix);
	else
		return (fx);
}

Fixed& Fixed::max(Fixed &fix, Fixed &fx)
{
	if (fix > fx)
		return (fix);
	else
		return (fx);
}

const Fixed Fixed::min(const Fixed fix, const Fixed fx)
{
	if (fix < fx)
		return (fix);
	else
		return (fx);
}

const Fixed Fixed::max(const Fixed fix, const Fixed fx)
{
	if (fix > fx)
		return (fix);
	else
		return (fx);
}