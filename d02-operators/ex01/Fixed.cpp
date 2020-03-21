
#include "Fixed.hpp"

Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &fixed){
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}
Fixed::Fixed(const int d){
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_value = (d << this->_fractional_bits);
}
Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = roundf(f * (1 << _fractional_bits));
}


Fixed& Fixed::operator = (const Fixed &fixed){
	std::cout << "Assignation operator called" << std::endl;
	this->_fixed_point_value = fixed.getRawBits();
	return (*this);
}

std::ostream &	operator<<(std::ostream & os, Fixed const & fixed){
	os << fixed.toFloat();
	return (os);
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}



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