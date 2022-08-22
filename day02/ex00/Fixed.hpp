#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int	fixednbr;
		static const int fixedfract = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed &obj);
		Fixed &operator = (const Fixed &fixed);
		int getRawBits(void)const;
		void setRawBits(int const raw);
};
#endif