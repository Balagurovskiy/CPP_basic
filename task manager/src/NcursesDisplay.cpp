#include "NcursesDisplay.hpp"


NcursesDisplay::NcursesDisplay() {
	win = initscr();
	bool b = true;
	clear();
	curs_set(0);
	timeout(-1);
	noecho();
	cbreak();
	keypad(win, true);
	nodelay(win, true);
}
NcursesDisplay::NcursesDisplay(const NcursesDisplay &copy) { *this = copy; }
NcursesDisplay::~NcursesDisplay() {endwin();}

NcursesDisplay &NcursesDisplay::operator=(const NcursesDisplay &copy) {
	if (this != &copy)
		*this = copy;
	return *this;
}


void			NcursesDisplay::setRenderer(SDL_Renderer *renderer, TTF_Font *font, SDL_Texture *texture)
{
	(void) renderer;
	(void) font;
	(void) renderer;
}

SDL_Color			NcursesDisplay::set_color(int r, int g, int b)
{
	SDL_Color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}



void		NcursesDisplay::renderText(char *mssg, int i)
{
		mvprintw(i, 0, mssg);
}

void		NcursesDisplay::draw(std::vector<std::string> line, int graphics)
{	
	
	for (int i = 0; i < line.size(); ++i) {
		renderText(const_cast<char *>(line.at(i).c_str()), graphics + i);	
	}	
}


