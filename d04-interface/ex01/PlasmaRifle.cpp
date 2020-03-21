
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(){
	_name = "Plasma Rifle";
	_apcost = 5;
	_damage = 21;
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle & aw){
	*this = aw;
}

PlasmaRifle &	PlasmaRifle::operator = (PlasmaRifle const & aw){
	_name = aw.getName();
	_apcost = aw.getAPCost();
	_damage = aw.getDamage();
	return (*this);
}

PlasmaRifle::~PlasmaRifle(){
}
// // // // // // // // // // // // // // // // // 
void			PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}