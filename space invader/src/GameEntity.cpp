/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:26:27 by abutok            #+#    #+#             */
/*   Updated: 2019/06/30 22:40:13 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "GameEntity.hpp"
#include "Enemy.hpp"
#include "stdlib.h"

int GameEntity::_maxx = 0;
int GameEntity::_maxy = 0;

GameEntity::GameEntity():
		_x(0),
		_y(0),
		_h(0),
		_pattern(NULL){
}


GameEntity::GameEntity(int x, int y, int h, std::string *pattern):
		_x(x),
		_y(y),
		_h(h){
	if (pattern != NULL)
		_pattern = pattern;
	else {
		h = 0;
		_pattern = NULL;
	}
}

GameEntity::GameEntity(const GameEntity &gameEntity) {
	_x = gameEntity._x;
	_y = gameEntity._y;
	_h = gameEntity._h;
	if (_h != 0)
		_pattern = new std::string[_h];
	for (int i = 0; i < _h; i++)
		_pattern[i] = std::string(gameEntity._pattern[i]);

}

GameEntity::~GameEntity() {
	delete [] _pattern;
}

GameEntity &GameEntity::operator=(const GameEntity &gameEntity) {
	_x = gameEntity._x;
	_y = gameEntity._y;
	_h = gameEntity._h;
	delete [] _pattern;
	if (_h != 0)
		_pattern = new std::string[_h];
	for (int i = 0; i < _h; i++)
		_pattern[i] = std::string(gameEntity._pattern[i]);
	return *this;
}

void GameEntity::draw() const {
	for (int i = 0; i < (int)_h; i++)
		for(int j = 0; j < (int)_pattern[i].length(); j++)
			if (_y + i >= 0 && _y + i < _maxy
				&& _x + j >= 0 && _x + j < _maxx)
					mvaddch(_y + j, _x + i, _pattern[i][j]);

}

void GameEntity::moveX(int x) {
	if (_x + x < _maxx && _x + x  >= 0)
		_x += x;
}

void GameEntity::moveY(int y) {
	if (_y + y < _maxy && _y + y  >= 0)
		_y += y;
}

bool GameEntity::isValid() const {
	return _h != 0;
}

bool GameEntity::isIntersected(const GameEntity &gameEntity) {
	for (int i = 0; i < (int)gameEntity._h; i++)
		for (int j = 0; j < (int)gameEntity._pattern[i].length(); j++)
			for (int k = 0; k < (int)_h; k++)
				for (int a = 0; a < (int)_pattern[k].length(); a++)
					if (_x + a == gameEntity._x + j &&
						_y + k == gameEntity._y + i)
						return true;
	return (false);
}

void GameEntity::setXY(int x, int y) {
		_x = x;
		_y = y;
}

void GameEntity::getMaxXY(WINDOW *win) {
	getmaxyx(win, _maxy, _maxx);
}

bool GameEntity::isIntersected(const Enemy &gameEntity) {
	for (int i = 0; i < (int)gameEntity._h; i++)
		for (int j = 0; j < (int)gameEntity._pattern[i].length(); j++)
			for (int k = 0; k < (int)_h; k++)
				for (int a = 0; a < (int)_pattern[k].length(); a++)
					if (_x + a == gameEntity._x - j &&
						_y + k == gameEntity._y + i)
						return true;
	return (false);
}

int GameEntity::getX() const {
	return _x;
}

int GameEntity::getY() const {
	return _y;
}

int GameEntity::getH() const {
	return _h;
}

std::string *GameEntity::getPattern() const {
	return _pattern;
}

int GameEntity::getMaxx() {
	return _maxx;
}

int GameEntity::getMaxy() {
	return _maxy;
}
