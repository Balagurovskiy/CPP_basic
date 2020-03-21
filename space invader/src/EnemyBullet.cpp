/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBullet.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:20:21 by abutok            #+#    #+#             */
/*   Updated: 2019/06/30 15:59:51 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "EnemyBullet.hpp"


EnemyBullet::EnemyBullet(): Bullet(-10, -10, 1, new std::string[1], 10){
	_pattern[1] = "-";
}

EnemyBullet::EnemyBullet(const EnemyBullet &enemyBullet): Bullet(enemyBullet) {

}

EnemyBullet::~EnemyBullet() {

}

EnemyBullet &EnemyBullet::operator=(const EnemyBullet &bullet) {
	(*this).Bullet::operator=(bullet);
	return *this;
}

void EnemyBullet::move() {
	_x--;
}

bool EnemyBullet::isEdge() const{
	return _x == 0;
}
