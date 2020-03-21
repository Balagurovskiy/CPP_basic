

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{

	public:

		PowerFist();
		PowerFist(const PowerFist & obj);

		PowerFist &	operator = (PowerFist const & obj);

		virtual void	attack() const;

		virtual ~PowerFist();
};

#endif