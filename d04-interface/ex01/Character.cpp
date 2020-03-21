
#include "Character.hpp"

Character::Character(){
	_name = "Character";
	_weapon = NULL;
	_AP = 40;
}

Character::Character(std::string const & name){
	_name = name;
	_weapon = NULL;
	_AP = 40;
}

Character::Character(const Character & c){
	*this = c;
}

Character &	Character::operator = (Character const & c){
	_name = c.getName();
	_weapon = c.getWeapon();
	_AP = c.getAP();
	return (*this);
}

Character::~Character(){
}

// // // // // // // // // // // // // // // // //

std::string const &		Character::getName() const{
	return (_name);
}
AWeapon *				Character::getWeapon() const{
	return (_weapon);
}
int						Character::getAP() const{
	return (_AP);
}

// // // // // // // // // // // // // // // // //

void					Character::attack(Enemy* target){
	bool targetIsAlive = (target->getHP() > 0);
	if (_weapon && targetIsAlive){
		int weaponApAmount = _weapon->getAPCost();
		bool canUseWeapon = ((_AP - weaponApAmount) >= 0);
		if (canUseWeapon){
			std::cout << _name << " attacks " << target->getType() << " with a " << _weapon->getName() << std::endl;
			_weapon->attack();
			target->takeDamage(_weapon->getDamage());
			_AP -= weaponApAmount;
		}
	}	
}
void					Character::recoverAP(){
	_AP += 10;
	if (_AP > 40)
		_AP = 40;
}
void					Character::equip(AWeapon* weapon){
	_weapon = weapon;
}

// // // // // // // // // // // // // // // // //

std::ostream &	operator << (std::ostream & o, Character const & c){
	o << c.getName() << " has " << c.getAP();
	if (c.getWeapon())
		o << " AP and wields a " << c.getWeapon()->getName() << std::endl;
	else
		o << " AP and is unarmed" << std::endl;
	return (o);
}