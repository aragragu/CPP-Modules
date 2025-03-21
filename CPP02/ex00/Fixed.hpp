#ifndef FIXED_H
#define FIXED_H


#include <iostream>

class Fixed
{
private:
	int	fixed_point;
	static const int	fract_bit;
public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed& operator=(const Fixed &src);
	~Fixed();


	int	getRawBits(void) const;
	void setRawBits(int const raw);
};



#endif
