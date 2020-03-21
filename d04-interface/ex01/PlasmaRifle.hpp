
#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{

	public:

		PlasmaRifle();
		PlasmaRifle(const PlasmaRifle & obj);

		PlasmaRifle &	operator = (PlasmaRifle const & obj);

		virtual void	attack() const;

		virtual ~PlasmaRifle();
};

#endif