

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
private:
	int					_fixed_point_value;
	static int const	_fractional_bits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	Fixed(const int d);
	Fixed(const float f);

	Fixed& operator = (const Fixed &fixed);
	bool	operator > (const Fixed &fixed) const;
	bool	operator < (const Fixed &fixed) const;
	bool	operator >=(const Fixed &fixed) const;
	bool	operator <=(const Fixed &fixed) const;
	bool	operator ==(const Fixed &fixed) const;
	bool	operator !=(const Fixed &fixed) const;

	Fixed	operator + (const Fixed &fixed) const;
	Fixed	operator - (const Fixed &fixed) const;
	Fixed	operator * (const Fixed &fixed) const;
	Fixed	operator / (const Fixed &fixed) const;

	Fixed&	operator ++(void);
	Fixed	operator ++(int);
	Fixed&	operator --(void);
	Fixed	operator --(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	~Fixed();

	static Fixed&			min(Fixed &a, Fixed &b);
	static Fixed&			max(Fixed &a, Fixed &b);
	static const Fixed&		min(const Fixed &a, const Fixed &b);
	static const Fixed&		max(const Fixed &a, const Fixed &b);
};

std::ostream &	operator<<(std::ostream & os, Fixed const & Fixed);

#endif