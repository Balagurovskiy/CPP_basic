
#ifndef A_H
# define A_H

#include "Base.hpp"

class	A : public Base
{
	public:
		A(void);
		A(A &a);
		A &operator=(A const &a);
		virtual ~A(void);
}; 

#endif