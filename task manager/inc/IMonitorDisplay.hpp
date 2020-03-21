#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include  "SDL_Handler.hpp"

class IMonitorDisplay {
public:
	virtual ~IMonitorDisplay(){};

	virtual void		setRenderer(SDL_Renderer *renderer, TTF_Font *font, SDL_Texture *texture) = 0;
	virtual SDL_Color	set_color(int r, int g, int b) = 0;
	virtual void		renderText(char *mssg, int i) = 0;
	virtual void		draw(std::vector<std::string> line, int graphic) = 0;
};
#endif