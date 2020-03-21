#include "A.hpp"

A::A(void)
{}

A::A(A &a)
{
	*this = a;
}

A & A::operator=(A const &a) 
{
	(void)a;
	return (*this);
}

A::~A(void)
{}