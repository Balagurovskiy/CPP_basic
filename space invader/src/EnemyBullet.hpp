/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBullet.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:18:10 by abutok            #+#    #+#             */
/*   Updated: 2019/06/30 16:01:20 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_ENEMYBULLET_HPP
#define FT_RETRO_ENEMYBULLET_HPP


#include "Bullet.hpp"

class EnemyBullet: public Bullet {
public:
	EnemyBullet();
	EnemyBullet(int x, int y);
	EnemyBullet(const EnemyBullet &enemyBullet);
	virtual ~EnemyBullet();
	EnemyBullet &operator=(const EnemyBullet &bullet);

	virtual void move();
	virtual bool isEdge() const;

};


#endif //FT_RETRO_ENEMYBULLET_HPP
