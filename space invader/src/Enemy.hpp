/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:16:47 by abutok            #+#    #+#             */
/*   Updated: 2019/06/30 17:40:14 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_ENEMY_HPP
#define FT_RETRO_ENEMY_HPP

#include <string>
#include "GameEntity.hpp"

class Bullet;

class Enemy: public GameEntity {
private:
	int		_hp;
protected:
	Enemy();
public:
	Enemy(int x, int y, int h, std::string *, int hp);
	Enemy(const Enemy &);
	virtual ~Enemy();
	Enemy &operator=(const Enemy &);

	virtual void draw() const;
	virtual void attack(Bullet &bullet) const = 0;
	virtual bool isIntersected(const Enemy &);
	virtual bool isIntersected(const GameEntity &);
	virtual void takeDamage(int dmg);
	int getHp() const;

};


#endif //FT_RETRO_ENEMY_HPP
