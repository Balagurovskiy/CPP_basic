#include "DisplayClass.hpp"

DisplayClass::DisplayClass() {}
DisplayClass::DisplayClass(const DisplayClass &copy) { *this = copy; }
DisplayClass::~DisplayClass() { }

DisplayClass &DisplayClass::operator=(const DisplayClass &copy) {
	if (this != &copy)
		*this = copy;
	return *this;
}

void			DisplayClass::setRenderer(SDL_Renderer *renderer, TTF_Font *font, SDL_Texture *texture)
{
	this->renderer = renderer;
	this->font = font;
	this->texture = texture;
}

SDL_Color			DisplayClass::set_color(int r, int g, int b)
{
	SDL_Color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

void		DisplayClass::renderText(char *mssg, int i)
{
	SDL_Surface *surf_massage;
	SDL_Texture	*texture;
	SDL_Rect	tmp;

	tmp = this->rect;
	tmp.x += 10;
	tmp.y += 30 * i;
	surf_massage = TTF_RenderText_Solid(this->font, mssg, set_color(255, 255, 255));
	texture = SDL_CreateTextureFromSurface(this->renderer, surf_massage);
	tmp.h = surf_massage->h;
	tmp.w = surf_massage->w;
	SDL_RenderCopy(this->renderer, texture, NULL, &tmp);
	SDL_FreeSurface(surf_massage);
	SDL_DestroyTexture(texture);
}