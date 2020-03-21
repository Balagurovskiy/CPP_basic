#include "BonusDisplay.hpp"

BonusDisplay::BonusDisplay() {}
BonusDisplay::BonusDisplay(const BonusDisplay &copy) { *this = copy; }
BonusDisplay::~BonusDisplay() { }

BonusDisplay &BonusDisplay::operator=(const BonusDisplay &copy) {
	if (this != &copy)
		*this = copy;
	return *this;
}

void		BonusDisplay::setText()
{
	this->rect.x = this->location.x + 10;
	this->rect.y = this->location.y + 10;
}


void		BonusDisplay::setLocation()
{
	int addFreeSpace = 20;
	this->location.x = W / 2;
	this->location.y = H * 2 / 3 + addFreeSpace;
	this->location.w = W / 3 + 5 - addFreeSpace;
	this->location.h = /*H * 2 / 3*/210 - addFreeSpace;
	SDL_SetRenderDrawColor(this->renderer,  47, 76, 168, 0xFF);		
	SDL_RenderFillRect(this->renderer, &this->location );
	SDL_Rect outline = {this->location.x + 5, this->location.y + 5,	this->location.w  - 10, this->location.h - 10};
	 SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00 );
	 SDL_RenderDrawRect( this->renderer, &outline );
}



void		BonusDisplay::draw(std::vector<std::string> line, int graphics)
{	
	graphics = 0;
	setLocation();
	setText();
	for (int i = 0; i < line.size(); ++i) {
		renderText(const_cast<char *>(line.at(i).c_str()), i);
	}
}	



