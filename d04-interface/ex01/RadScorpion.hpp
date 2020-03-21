
#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include <iostream>
#include "Enemy.hpp"

class RadScorpion : public Enemy
{
	public:

		RadScorpion();
		RadScorpion(const RadScorpion & o);

		RadScorpion &	operator = (RadScorpion const & o);

		virtual void	takeDamage(int damage);

		virtual ~RadScorpion();
};

#endif