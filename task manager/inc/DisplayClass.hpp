#ifndef DISPLAYCLASS_HPP
# define DISPLAYCLASS_HPP

#include "IMonitorDisplay.hpp"

class DisplayClass : public IMonitorDisplay
{

public:
	DisplayClass();
	DisplayClass(DisplayClass const &copy);
	virtual ~DisplayClass();
	DisplayClass &operator=(const DisplayClass &copy);

	void		setRenderer(SDL_Renderer *renderer, TTF_Font *font, SDL_Texture *texture);
	SDL_Color	set_color(int r, int g, int b);
	void		renderText(char *mssg, int i);

protected:
	SDL_Rect		location;
	SDL_Renderer	*renderer;
	TTF_Font		*font;
	SDL_Rect		rect;
	SDL_Texture		*texture;
};

#endif