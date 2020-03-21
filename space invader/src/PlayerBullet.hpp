
#ifndef FT_RETRO_PLAYERULLET_HPP
#define FT_RETRO_PLAYERULLET_HPP


#include "Bullet.hpp"

class PlayerBullet: public Bullet {
private:

public:
	PlayerBullet();
	PlayerBullet(int x, int y);
	PlayerBullet(const PlayerBullet &pb);
	virtual ~PlayerBullet();
	PlayerBullet &operator=(const PlayerBullet &bullet);

	virtual void move();
	virtual bool isEdge() const;

};


#endif
