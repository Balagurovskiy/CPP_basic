
#include "C.hpp"

C::C(void)
{}

C::C(C &c)
{
	*this = c;
}

C & C::operator=(C const &c) 
{
	(void)c;
	return (*this);
}

C::~C(void)
{}