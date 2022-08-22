#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int	fixednbr;
		static const int fixedfract = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &obj);
		Fixed (const int nbr);
		Fixed (const float nb);
		Fixed &operator = (const Fixed &fixed);
		int getRawBits(void)const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int		toInt(void) const;
		};
int power(int number, int pow);
std::ostream& operator<<(std::ostream& os, const Fixed& fix);
#endif