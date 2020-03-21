/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OrdinaryEnemy.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:06:51 by abutok            #+#    #+#             */
/*   Updated: 2019/06/30 17:12:25 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_ORDINARYENEMY_HPP
#define FT_RETRO_ORDINARYENEMY_HPP


#include "Enemy.hpp"

class EnemyBullet;

class OrdinaryEnemy: public Enemy {
protected:
	OrdinaryEnemy();
public:
	OrdinaryEnemy(int x, int y);
	OrdinaryEnemy(const OrdinaryEnemy &ordinaryEnemy);
	~OrdinaryEnemy();
	OrdinaryEnemy &operator=(const OrdinaryEnemy &ordinaryEnemy);

	virtual void attack(Bullet &bullet) const;
};


#endif //FT_RETRO_ORDINARYENEMY_HPP
