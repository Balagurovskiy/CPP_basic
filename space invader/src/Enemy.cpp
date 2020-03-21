/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:16:53 by abutok            #+#    #+#             */
/*   Updated: 2019/06/30 22:43:52 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Enemy.hpp"
#include "GameEntity.hpp"

Enemy::Enemy(int x, int y, int h, std::string *_pattern, int hp): GameEntity(x,y, h, _pattern){
	_hp = hp;
}

Enemy::Enemy(const Enemy &enemy): GameEntity(enemy) {
	_hp = enemy._hp;
}

Enemy::~Enemy() {}

Enemy &Enemy::operator=(const Enemy &enemy) {
	(*this).GameEntity::operator=(enemy);
	_hp = enemy._hp;
	return *this;
}

Enemy::Enemy() {}

void Enemy::draw() const {
	for (int i = 0; i <(int) _h; i++)
		for(int j = 0; j < (int)_pattern[i].length(); j++)
			if (_y + i >= 0 && _y + i < _maxy
				&& _x - j >= 0 && _x - j < _maxx)
				mvaddch(_y + i, _x - j, _pattern[i][j]);
}

bool Enemy::isIntersected(const Enemy &gameEntity) {
	for (int i = 0; i < (int)gameEntity._h; i++)
		for (int j = 0; j < (int)gameEntity._pattern[i].length(); j++)
			for (int k = 0; k < (int)_h; k++)
				for (int a = 0; a < (int)_pattern[k].length(); a++)
					if (_x - a == gameEntity._x - j &&
						_y + k == gameEntity._y + i)
						return true;
	return (false);
}

bool Enemy::isIntersected(const GameEntity &gameEntity) {
	for (int i = 0; i < (int)gameEntity.getH(); i++)
		for (int j = 0; j < (int)gameEntity.getPattern()[i].length(); j++)
			for (int k = 0; k < (int)_h; k++)
				for (int a = 0; a < (int)_pattern[k].length(); a++)
					if (_x - a == gameEntity.getX() + j &&
						_y - k == gameEntity.getX() + i)
						return true;
	return (false);
}

int Enemy::getHp() const {
	return _hp;
}

void Enemy::takeDamage(int dmg) {
	if (dmg >= _hp)
		_hp = 0;
	else
		_hp -=dmg;
}
