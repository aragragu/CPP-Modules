#ifndef FIXED_H
#define FIXED_H


#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	fixed_point;
	static const int	fract_bit;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &src);
	Fixed& operator=(const Fixed &src);
	~Fixed();
	float toFloat(void) const;
	int	toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
