
#include "AWeapon.hpp"

AWeapon::AWeapon(){
	_name = "Weapon";
	_apcost = 0;
	_damage = 0;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage){
	_name = name;
	_apcost = apcost;
	_damage = damage;
}

AWeapon::AWeapon(const AWeapon & aw){
	*this = aw;
}

AWeapon &	AWeapon::operator = (AWeapon const & aw){
	_name = aw.getName();
	_apcost = aw.getAPCost();
	_damage = aw.getDamage();
	return (*this);
}

AWeapon::~AWeapon(){
}
// // // // // // // // // // // // // // // // // 
std::string const &	AWeapon::getName() const{
	return (_name);
}
int					AWeapon::getAPCost() const{
	return (_apcost);
}
int					AWeapon::getDamage() const{
	return (_damage);
}
