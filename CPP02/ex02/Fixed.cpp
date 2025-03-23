#include "Fixed.hpp"

const int Fixed::fract_bit = 8;

Fixed::Fixed() : fixed_point(0){
}

Fixed::~Fixed(){
}

Fixed::Fixed(const Fixed &src){
	*this = src;
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

Fixed& Fixed::operator=(const Fixed &src){
	if (this == &src)
		return *this;
	this->fixed_point = src.fixed_point;
	return *this;
}

bool Fixed::operator<(const Fixed& src){
	return (this->fixed_point < src.fixed_point);
}

bool Fixed::operator>(const Fixed &src){
	return (this->fixed_point > src.fixed_point);
}

bool Fixed::operator>=(const Fixed &src){
	return (this->fixed_point >= src.fixed_point);
}

bool Fixed::operator<=(const Fixed &src){
	return (this->fixed_point <= src.fixed_point);
}

bool Fixed::operator==(const Fixed &src){
	return (this->fixed_point == src.fixed_point);
}

bool Fixed::operator!=(const Fixed &src){
	return (this->fixed_point != src.fixed_point);
}

Fixed Fixed::operator+(const Fixed& src) const{
	return (Fixed(this->fixed_point + src.fixed_point));
}

Fixed Fixed::operator-(const Fixed &src) const{
	return (Fixed(this->fixed_point - src.fixed_point));
}

Fixed Fixed::operator*(const Fixed &src) const
{
	Fixed res;
	res.setRawBits((this->fixed_point * src.fixed_point) >> fract_bit);
	return res;
}

Fixed Fixed::operator/(const Fixed &src) const
{
	Fixed res;
	res.setRawBits((this->fixed_point << fract_bit) / src.fixed_point);
	return res;
}

Fixed& Fixed::operator++(){
	this->fixed_point++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed temp(*this);
	this->fixed_point++;
	return temp;
}

Fixed &Fixed::operator--(){
	this->fixed_point--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed temp(*this);
	this->fixed_point--;
	return temp;
}

Fixed::Fixed(const int value){
	fixed_point = value << fract_bit;
}

Fixed::Fixed(const float value){
	fixed_point = roundf(value * (1 << fract_bit));
}

float Fixed::toFloat(void) const{
	return (float)fixed_point / (1 << fract_bit);
}

int Fixed::toInt(void) const{
	return fixed_point >> fract_bit;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
	out << fixed.toFloat();
	return out;
}

Fixed& Fixed::min(Fixed &S1, Fixed &S2){
	if (S1.fixed_point < S2.fixed_point)
		return S1;
	return S2;
}

const Fixed& Fixed::min(const Fixed &fixed_1, const Fixed &fixed_2){
	if (fixed_1.fixed_point < fixed_2.fixed_point)
		return fixed_1;
	return fixed_2;
}

Fixed& Fixed::max(Fixed &S1, Fixed &S2){
	if (S1.fixed_point > S2.fixed_point)
		return S1;
	return S2;
}

const Fixed& Fixed::max(const Fixed &S1, const Fixed &S2){
	if (S1.fixed_point > S2.fixed_point)
		return S1;
	return S2;
}
