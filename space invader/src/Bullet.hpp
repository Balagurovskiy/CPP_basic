/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:56:17 by abutok            #+#    #+#             */
/*   Updated: 2019/06/30 15:59:51 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_BULLET_HPP
#define FT_RETRO_BULLET_HPP

#include "GameEntity.hpp"

class Bullet: public GameEntity {
protected:
	int		_dmg;
	Bullet();
public:
	Bullet(int x, int y, int h, std::string *p, int dmg);
	Bullet(const Bullet &);
	Bullet &operator=(const Bullet &);
	virtual ~Bullet();

	virtual void move() = 0;
	virtual bool isEdge() const = 0;
	int getDmg() const;
	virtual bool status();
};


#endif //FT_RETRO_BULLET_HPP
