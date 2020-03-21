
#include "PowerFist.hpp"

PowerFist::PowerFist(){
	_name = "Power Fist";
	_apcost = 8;
	_damage = 50;
}

PowerFist::PowerFist(const PowerFist & aw){
	*this = aw;
}

PowerFist &	PowerFist::operator = (PowerFist const & aw){
	_name = aw.getName();
	_apcost = aw.getAPCost();
	_damage = aw.getDamage();
	return (*this);
}

PowerFist::~PowerFist(){
}
// // // // // // // // // // // // // // // // // 
void			PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}