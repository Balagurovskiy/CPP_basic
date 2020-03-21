

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(){
	_type = "RadScorpion";
	_hp = 80;
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & o){
	*this = o;
	std::cout << "* click click click *" << std::endl;
}

RadScorpion &	RadScorpion::operator = (RadScorpion const & o){
	_hp = o.getHP();
	_type = o.getType();
	return (*this);
}

RadScorpion::~RadScorpion(){
	std::cout << "* SPROTCH *" << std::endl;
}
// // // // // // // // // // // // // // // // // 

void	RadScorpion::takeDamage(int damage){
	if (damage < 0)
		return ;
	_hp -= damage;
	if (_hp <= 0)
		RadScorpion::~RadScorpion();
}