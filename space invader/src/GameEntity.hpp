/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:26:15 by abutok            #+#    #+#             */
/*   Updated: 2019/06/30 15:54:09 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_GAMEENTITY_HPP
#define FT_RETRO_GAMEENTITY_HPP

#include <string>
#include <ncurses.h>

class Enemy;

class GameEntity {
protected:
	int			_x;
	int			_y;
	int			_h;
	std::string	*_pattern;
	static int	_maxx;
public:
	static int getMaxx();

	static int getMaxy();

protected:
	static int	_maxy;
	GameEntity();
public:
	GameEntity(int _x, int _y, int _h, std::string *);
	GameEntity(const GameEntity &);
	virtual ~GameEntity();
	GameEntity &operator=(const GameEntity &);

	virtual void draw() const;
	void setXY(int x, int y);
	void moveX(int x);
	void moveY(int y);
	virtual bool isIntersected(const Enemy &);
	virtual bool isIntersected(const GameEntity &);
	bool isValid() const;
	static void getMaxXY(WINDOW *);

	int getX() const;

	int getY() const;

	int getH() const;

	std::string *getPattern() const;
};


#endif //FT_RETRO_GAMEENTITY_HPP
