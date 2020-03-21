#include "CpuDisplay.hpp"

CpuDisplay::CpuDisplay() {max =2;}
CpuDisplay::CpuDisplay(const CpuDisplay &copy) { *this = copy; }
CpuDisplay::~CpuDisplay() { }

CpuDisplay &CpuDisplay::operator=(const CpuDisplay &copy) {
	if (this != &copy)
		*this = copy;
	return *this;
}


void		CpuDisplay::setLocation()
{	
	int addFreeSpace = 25;
	this->location.x = addFreeSpace;
	this->location.y = H / 2 + addFreeSpace;
	this->location.w = W / 2 - addFreeSpace * 4;
	this->location.h = H / 2 - addFreeSpace * 2;
	SDL_SetRenderDrawColor(this->renderer, 133, 44, 164, 0xFF);		
	SDL_RenderFillRect(this->renderer, &this->location );

	SDL_Rect outline = {this->location.x + 5, this->location.y + 5,	this->location.w  - 10, this->location.h  - 10};
	 SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00 );
	 SDL_RenderDrawRect( this->renderer, &outline );

}

void		CpuDisplay::setText()
{
	this->rect.x = this->location.x + 10;
	this->rect.y = this->location.y + 10;
}

void		CpuDisplay::draw(std::vector<std::string> line, int graphic)
{	
	setLocation();
	setText();
	for (int i = 0; i < line.size(); ++i)
		renderText(const_cast<char *>(line.at(i).c_str()), i);

		int i = 0;
		SDL_Rect graph[75];
		int 	save[75];

		graph[i].x = this->location.x + 7;
		graph[i].y = this->location.y + 120 + (140 - graphic);
		graph[i].w = 5;
		graph[i].h = this->location.h - 125 - (140 - graphic);
		SDL_SetRenderDrawColor(this->renderer, 0x18, 0xd1, 0x09, 0x00 );
		SDL_RenderFillRect(this->renderer, &graph[0]);
		save[0] = this->location.y + 120 + (140 - graphic);
	if (max >=74) max = 1;
	
	for (int i = 1; i < max; i++)
	{
		graph[i].x = graph[i - 1].x + graph[i - 1].w + 2;
		graph[i].y = graph[i - 1].y;
		graph[i].w = 5;
		graph[i].h = graph[i - 1].h;		
	}
	for (int i = 1; i < max; i++)
	{
		SDL_SetRenderDrawColor(this->renderer, 0x18, 0xd1, 0x09, 0x00 );
		SDL_RenderFillRect(this->renderer, &graph[i]);
	}
	for (int i = max - 1; i > 1; i--){
		save[i] = save[i - 1];
	}
	max++;
}