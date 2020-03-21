
#ifndef B_H
# define B_H

#include "Base.hpp"

class	B : public Base
{
	public:
		B(void);
		B(B &b);
		B &operator=(B const &b);
		virtual ~B(void);
}; 

#endif