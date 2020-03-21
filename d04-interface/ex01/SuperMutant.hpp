
#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include <iostream>
#include "Enemy.hpp"

class SuperMutant : public Enemy
{
	public:

		SuperMutant();
		SuperMutant(const SuperMutant & o);

		SuperMutant &	operator = (SuperMutant const & o);

		virtual void	takeDamage(int damage);

		virtual ~SuperMutant();
};

#endif