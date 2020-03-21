

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(){
	_type = "Super Mutant";
	_hp = 170;
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & o){
	*this = o;
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant &	SuperMutant::operator = (SuperMutant const & o){
	_hp = o.getHP();
	_type = o.getType();
	return (*this);
}

SuperMutant::~SuperMutant(){
	std::cout << "Aaargh ..." << std::endl;
}
// // // // // // // // // // // // // // // // // 

void	SuperMutant::takeDamage(int damage){
	damage -= 3;
	if (damage < 0)
		return ;
	_hp -= damage;
	if (_hp <= 0)
		SuperMutant::~SuperMutant();
}