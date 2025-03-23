#include "Fixed.hpp"

const int Fixed::fract_bit = 4;

Fixed::Fixed() : fixed_point(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	this->fixed_point = src.fixed_point;
	return *this;
}


Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point = value << fract_bit;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point = roundf(value * (1 << fract_bit));
}

float Fixed::toFloat(void) const{
	return (float)fixed_point / (1 << fract_bit);
}

int Fixed::toInt(void) const{
	return fixed_point >> fract_bit;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}
