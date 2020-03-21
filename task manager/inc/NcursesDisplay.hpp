#ifndef NCURSESDISPLAY_HPP
# define NCURSESDISPLAY_HPP

#include  "SDL_Handler.hpp"
#include  "IMonitorDisplay.hpp"
#include <iostream>
#include <ncurses.h>
#include <zconf.h>

class NcursesDisplay : public IMonitorDisplay
{
	public:
		NcursesDisplay();
		NcursesDisplay(NcursesDisplay const &copy);
		~NcursesDisplay();

		NcursesDisplay &operator=(const NcursesDisplay &copy);

		 void		setRenderer(SDL_Renderer *renderer, TTF_Font *font, SDL_Texture *texture);
		 SDL_Color	set_color(int r, int g, int b);
		 void		renderText(char *mssg, int i);
		 void		draw(std::vector<std::string> line, int graphic);
	private:
		WINDOW *win;
};

#endif