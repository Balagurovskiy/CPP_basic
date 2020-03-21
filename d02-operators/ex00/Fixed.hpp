#include <iostream>


#ifndef FIXED_HPP
#define FIXED_HPP

class	Fixed
{
private:
	int					_fixed_point_value;
	static int const	_fractional_bits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	Fixed& operator = (const Fixed &fixed);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif