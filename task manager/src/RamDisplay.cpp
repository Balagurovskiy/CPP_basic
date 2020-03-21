#include "RamDisplay.hpp"

RamDisplay::RamDisplay() {max = 2;}
RamDisplay::RamDisplay(const RamDisplay &copy) { *this = copy; }
RamDisplay::~RamDisplay() { }

RamDisplay &RamDisplay::operator=(const RamDisplay &copy) {
	if (this != &copy)
		*this = copy;
	return *this;
}

void		RamDisplay::setLocation()
{	
	// SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	// SDL_RenderClear( this->renderer );
	int addFreeSpace = 25;
	this->location.x = addFreeSpace;
	this->location.y = addFreeSpace;
	this->location.w = W / 2 - addFreeSpace * 4;
	this->location.h = H / 2 - addFreeSpace * 2;
	SDL_SetRenderDrawColor(this->renderer, 210, 61, 213, 0xFF );		
	SDL_RenderFillRect(this->renderer, &this->location );

	SDL_Rect outline = {this->location.x + 5, this->location.y + 5,	this->location.w  - 10, this->location.h  - 10};
	 SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00 );
	 SDL_RenderDrawRect( this->renderer, &outline );

}

void		RamDisplay::setText()
{
	this->rect.x = this->location.x + 10;
	this->rect.y = this->location.y + 10;
}

void		RamDisplay::draw(std::vector<std::string> line, int graphic)
{	
	setLocation();
	setText();
	for (int i = 0; i < line.size(); ++i)
		renderText(const_cast<char *>(line.at(i).c_str()), i);

		int i = 0;

		SDL_Rect graph[75];
		graph[i].x = this->location.x + 7;
		graph[i].y = this->location.y + 100 + (100 - graphic);
		graph[i].w = 5;
		graph[i].h = this->location.h - 105 - (100 - graphic);
		SDL_SetRenderDrawColor(this->renderer, 0xA6, 0x24, 0x24, 0x00 );	
		SDL_RenderFillRect(this->renderer, &graph[0]);
	if (max >=74) max = 2;
	max++;
	for (int i = 1; i < max; i++)
	{
		graph[i].x = graph[i - 1].x + graph[i - 1].w + 2;
		graph[i].y = graph[i - 1].y;
		graph[i].w = 5;
		graph[i].h = graph[i - 1].h;		
	}
	for (int i = 1; i < max; i++)
	{		
		SDL_SetRenderDrawColor(this->renderer, 0xA6, 0x24, 0x24, 0x00 );	
		SDL_RenderFillRect(this->renderer, &graph[i]);
	}	
}
