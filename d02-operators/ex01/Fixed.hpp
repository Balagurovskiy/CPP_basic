

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

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	~Fixed();
};

std::ostream &	operator<<(std::ostream & os, Fixed const & Fixed);
#endif