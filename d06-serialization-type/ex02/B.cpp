
#include "B.hpp"

B::B(void)
{}

B::B(B &b)
{
	*this = b;
}

B & B::operator=(B const &b) 
{
	(void)b;
	return (*this);
}

B::~B(void)
{}