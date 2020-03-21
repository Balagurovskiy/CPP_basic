#include "PonyDisplay.hpp"

PonyDisplay::PonyDisplay() {}
PonyDisplay::PonyDisplay(const PonyDisplay &copy) { *this = copy; }
PonyDisplay::~PonyDisplay() { }

PonyDisplay &PonyDisplay::operator=(const PonyDisplay &copy) {
	if (this != &copy)
		*this = copy;
	return *this;
}

void		PonyDisplay::setLocation()
{	
	int addFreeSpace = 20;
	this->location.x = W / 2;
	this->location.y = H / 3 + addFreeSpace;
	this->location.w = W / 2 - addFreeSpace;
	this->location.h = H / 3 - addFreeSpace;
	SDL_SetRenderDrawColor(this->renderer, 85, 147, 197, 0xFF);		
	SDL_RenderFillRect(this->renderer, &this->location );
	SDL_Rect outline = {this->location.x + 5, this->location.y + 5,	this->location.w  - 10, this->location.h  - 10};
	 SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00 );
	 SDL_RenderDrawRect( this->renderer, &outline );
}

void		PonyDisplay::setText()
{
	this->rect.x = this->location.x + 10;
	this->rect.y = this->location.y + 10;
}

void		PonyDisplay::draw(std::vector<std::string> line, int graphics)
{	
	graphics = 0;
	setLocation();
	setText();
	for (int i = 0; i < line.size(); ++i) {
		renderText(const_cast<char *>(line.at(i).c_str()), i);		
	}
}