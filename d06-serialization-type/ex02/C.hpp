
#ifndef C_H
# define C_H

#include "Base.hpp"

class	C : public Base
{
	public:
		C(void);
		C(C &c);
		C &operator=(C const &c);
		virtual ~C(void);
}; 

#endif