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
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed& operator=(const Fixed &src);
	bool operator<(const Fixed& src);
	bool operator>(const Fixed &src);
	bool operator>=(const Fixed &src);
	bool operator<=(const Fixed &src);
	bool operator==(const Fixed &src);
	bool operator!=(const Fixed &src);
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	Fixed operator+(const Fixed &src) const;
	Fixed operator-(const Fixed &src) const;
	Fixed operator*(const Fixed &src) const;
	Fixed operator/(const Fixed &src) const;
	static Fixed &min(Fixed &S1, Fixed &S2);
	static const Fixed &min(const Fixed&fixed_1, const Fixed&fixed_2);
	static Fixed &max(Fixed &S1, Fixed &S2);
	static const Fixed &max(const Fixed &S1, const Fixed &S2);
	~Fixed();
	float toFloat(void) const;
	int	toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
