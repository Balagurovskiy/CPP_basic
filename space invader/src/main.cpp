#include <iostream>
#include <ncurses.h>
#include <zconf.h>
#include "EnemyBullet.hpp"
#include "Player.hpp"
#include "OrdinaryEnemy.hpp"

int main() {

	WINDOW *win = initscr();
	bool b = true;
	clear();
	curs_set(0);
	timeout(-1);
	noecho();
	cbreak();
	keypad(win, true);
	nodelay(win, true);

	PlayerBullet playerBullet[1000];
	Player		player;
	player.getMaxXY(win);
	const int k = 14;
	Enemy*		enemy[k];
	for (int i = 0; i < k; i++)
		enemy[i] = NULL;

	srand(std::time(0));
	size_t  op = 0;
	while(b)
	{
		player.getMaxXY(win);
		if (op % 1000 == 0)
		for (int i = 0; i < k; i++)
		{
			if (enemy[i] == NULL) {
				enemy[i] = new OrdinaryEnemy(200 + rand() % (i+1) + rand() % 17, rand() % player.getMaxy());
			}
		}
		erase();
		player.draw();
		int f = rand() % k;
		if (enemy[f] != NULL) {
			enemy[f]->setXY(enemy[f]->getX() - 1, enemy[f]->getY());
			if (enemy[f]->getX() < 0)
			{
				delete enemy[f];
				enemy[f] = NULL;
			}
		}
		for (int i = 0; i < k; i++)
		{
			if (enemy[i] != NULL) {
				enemy[i]->draw();
				if (player.isIntersected(*enemy[i])) {
					player.takeDamage(enemy[i]->getHp());
					delete enemy[i];
					enemy[i]=NULL;
				}
			}
		}
		for (int i = 0; i < 1000; i++)
		{
			if (playerBullet[i].status()) {
				playerBullet[i].draw();
				for (int j = 0; j < k; j++)
				{
					if (enemy[j] != NULL && (playerBullet[i].isIntersected(*enemy[j])))
					{
						enemy[j]->takeDamage(playerBullet[i].getDmg());
						playerBullet[i].setXY(-10, -10);
						if (enemy[j]->getHp() == 0) {
							delete enemy[j];
							enemy[j] = NULL;
						}
						break;
					}
				}
				playerBullet[i].move();
			}
		}
		char c = wgetch(win);
		switch(c)
		{
			case 'q':
				b = !b;
				break;
			case 'w':
				player.moveY(-1);
				break;
			case 's':
				player.moveY(1);
				break;
			case 'd':
				player.moveX(1);
				break;
			case 'a':
				player.moveX(-1);
				break;
			case ' ':
			{
				int i = 0;
				while (i < 1000 && playerBullet[i].status())
					i++;
				player.attack(playerBullet[i]);
				break;
			}
			default:
				break;
		}
		usleep(5000);
		refresh();
		op++;
		if (player.getHp() == 0)
			break;
	}
	for (int i = 0; i < k; i++)
	{
		if (enemy[i]!= NULL) delete enemy[i];
	}
	endwin();
	std::cout <<"Game over"<< std::endl;
	return 0;
}
