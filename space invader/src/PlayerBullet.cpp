
#include <string>
#include "PlayerBullet.hpp"


PlayerBullet::PlayerBullet(): Bullet(-1, -1, 1, new std::string[1], 10) {
	_pattern[0] = "-";
}

PlayerBullet::PlayerBullet(const PlayerBullet &enemyBullet): Bullet(enemyBullet) {

}

PlayerBullet::~PlayerBullet() {

}

PlayerBullet &PlayerBullet::operator=(const PlayerBullet &bullet) {
	(*this).Bullet::operator=(bullet);
	return *this;
}

void PlayerBullet::move() {
	_x++;
}

PlayerBullet::PlayerBullet(int x, int y): Bullet(x,y, 1, new std::string[1], 10) {
	_pattern[0] = "-";
}

bool PlayerBullet::isEdge() const{
	return _x == 0;
}
