//
// Created by Andrii BUTOK on 2019-06-30.
//

#include "OrdinaryEnemy.hpp"
#include "EnemyBullet.hpp"

OrdinaryEnemy::OrdinaryEnemy() {}

OrdinaryEnemy::OrdinaryEnemy(const OrdinaryEnemy &ordinaryEnemy): Enemy(ordinaryEnemy) {

}

OrdinaryEnemy::~OrdinaryEnemy() {

}

OrdinaryEnemy &OrdinaryEnemy::operator=(const OrdinaryEnemy &ordinaryEnemy) {
	(*this).Enemy::operator=(ordinaryEnemy);
	return *this;
}

void	OrdinaryEnemy::attack(Bullet &bullet) const {
	bullet.setXY(_x - 2, _y + 1);
}

OrdinaryEnemy::OrdinaryEnemy(int x, int y): Enemy(x, y, 3, new std::string[3], 30) {
	_pattern[0] = "< ";
	_pattern[1] = "<<";
	_pattern[2] = "< ";
}
