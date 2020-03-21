/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:17:01 by abutok            #+#    #+#             */
/*   Updated: 2019/06/30 15:38:23 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"
#include "Bullet.hpp"

Bullet::Bullet(): GameEntity() {
	_dmg = 0;
}

Bullet::Bullet(const Bullet &bullet): GameEntity(bullet) {
	_dmg = bullet._dmg;
}

Bullet &Bullet::operator=(const Bullet &bullet) {
	(*this).GameEntity::operator=(bullet);
	_dmg = bullet._dmg;
	return *this;
}

Bullet::~Bullet() { }

int Bullet::getDmg() const {
	return _dmg;
}

Bullet::Bullet(int x, int y, int h, std::string *pattern, int dmg): GameEntity(x, y, h, pattern){
	_dmg = dmg;
}

bool Bullet::status() {
	return (_x >= 0 && _x < _maxx);
}
