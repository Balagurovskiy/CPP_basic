//
// Created by Olexiy BALAGUROVSKIY on 2019-06-30.
//

#include "Player.hpp"

Player::Player(int x, int y):GameEntity(x,y, 3, (new std::string[4])){
	_hp = 100;
	_h = 4;
	_pattern[0] = "= =";
	_pattern[1] = ">>>";
	_pattern[2] = " > ";
	_pattern[3] = " 0 ";
}

Player::Player(const Player &p) : GameEntity(p){
	_hp = p._hp;;
}

Player &Player::operator=(const Player &p) {
	(*this).GameEntity::operator=(p);
	_hp = p._hp;
	return *this;
}

Player::~Player() {
}




void 	Player::attack(Bullet &bullet) const{
	bullet.setXY(_x + 3, _y + 1);
}

int 	Player::getHp() const {
	return _hp;
}

void 	Player::takeDamage(int dmg){
	if (dmg > _hp)
		_hp = 0;
	else
		_hp -= dmg;
}

Player::Player(): GameEntity(0, 0, 4, (new std::string[4])){
	_hp = 100;
	_h = 4;
	_pattern[0] = "= =";
	_pattern[1] = ">>>";
	_pattern[2] = " > ";
	_pattern[3] = " 0 ";
}

