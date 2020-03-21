//
// Created by Olexiy BALAGUROVSKIY on 2019-06-30.
//

#ifndef RUSH_00_PLAYER_HPP
#define RUSH_00_PLAYER_HPP

#include "GameEntity.hpp"
#include "PlayerBullet.hpp"

class Player: public GameEntity  {
	private:
		int _hp;

	public:
		Player();
		Player(int x, int y);
		Player(const Player &);
		Player &operator=(const Player &);
		~Player();

		virtual void 	attack(Bullet &bullet) const;
		int 			getHp() const;
		void 			takeDamage(int dmg);
};


#endif //RUSH_00_PLAYER_HPP
