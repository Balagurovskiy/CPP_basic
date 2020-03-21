
#include "Fixed.hpp"
//			constructors
//- - - - - - - - - - - - - - - - - - - - - - - - 
Fixed::Fixed(void){
	this->_fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &fixed){
	*this = fixed;
}
Fixed::Fixed(const int d){
	this->_fixed_point_value = (d << this->_fractional_bits);
}
Fixed::Fixed(const float f){
	this->_fixed_point_value = roundf(f * (1 << _fractional_bits));
}

Fixed::~Fixed(void){
}

// 			get/set
//- - - - - - - - - - - - - - - - - - - - - - - - 
int		Fixed::getRawBits(void) const{
	return (this->_fixed_point_value);
}
void	Fixed::setRawBits(int const raw){
	this->_fixed_point_value = raw;
}

float	Fixed::toFloat(void) const{
	return ((float)this->_fixed_point_value / (1 << _fractional_bits));
}
int		Fixed::toInt(void) const{
	return (this->_fixed_point_value >> _fractional_bits);
}
//			operators
//- - - - - - - - - - - - - - - - - - - - - - - - 
//			operators	bool
//- - - - - - - - - - - - - - - - - - - - - - - - 
bool	Fixed::operator > (const Fixed &fixed) const{
	return (this->getRawBits() > fixed.getRawBits());
}
bool	Fixed::operator < (const Fixed &fixed) const{
	return (this->getRawBits() < fixed.getRawBits());
}
bool	Fixed::operator >=(const Fixed &fixed) const{
	return (this->getRawBits() >= fixed.getRawBits());
}
bool	Fixed::operator <=(const Fixed &fixed) const{
	return (this->getRawBits() <= fixed.getRawBits());
}
bool	Fixed::operator ==(const Fixed &fixed) const{
	return (this->getRawBits() == fixed.getRawBits());
}
bool	Fixed::operator !=(const Fixed &fixed) const{
	return (this->getRawBits() != fixed.getRawBits());
}
//			operators	math
//- - - - - - - - - - - - - - - - - - - - - - - - 
Fixed	Fixed::operator + (const Fixed &fixed) const{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}
Fixed	Fixed::operator - (const Fixed &fixed) const{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}
Fixed	Fixed::operator * (const Fixed &fixed) const{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}
Fixed	Fixed::operator / (const Fixed &fixed) const{
	if (fixed.toFloat() == 0.0)
		return (Fixed((float)0.0));
	return (Fixed(this->toFloat() / fixed.toFloat()));
}
//			operators	inc/dec
//- - - - - - - - - - - - - - - - - - - - - - - - 
Fixed&	Fixed::operator ++(void){
	this->_fixed_point_value++;
	return (*this);
}
Fixed	Fixed::operator ++(int){
	Fixed curr(*this);
	++*this;
	return (curr);
}
Fixed&	Fixed::operator --(void){
	this->_fixed_point_value--;
	return (*this);
}
Fixed	Fixed::operator --(int){
	Fixed curr(*this);
	--*this;
	return (curr);
}
//			operators	copy
//- - - - - - - - - - - - - - - - - - - - - - - - 
Fixed& Fixed::operator = (const Fixed &fixed){
	this->_fixed_point_value = fixed.getRawBits();
	return (*this);
}
//			operators non member
//- - - - - - - - - - - - - - - - - - - - - - - - 
std::ostream &	operator<<(std::ostream & os, Fixed const & fixed){
	os << fixed.toFloat();
	return (os);
}

//			static	
//- - - - - - - - - - - - - - - - - - - - - - - - 
Fixed&			Fixed::min(Fixed &f1, Fixed &f2){
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}
Fixed&			Fixed::max(Fixed &f1, Fixed &f2){
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}
const Fixed&	Fixed::min(const Fixed &f1, const Fixed &f2){
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}
const Fixed&	Fixed::max(const Fixed &f1, const Fixed &f2){
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}