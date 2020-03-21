#ifndef PONYDISPLAY_HPP
# define PONYDISPLAY_HPP

#include "DisplayClass.hpp"

class PonyDisplay : public DisplayClass
{
public:
	PonyDisplay();
	PonyDisplay(PonyDisplay const &copy);
	~PonyDisplay();
	PonyDisplay &operator=(const PonyDisplay &copy);

	void		setLocation();
	void		setText();
	void		draw(std::vector<std::string> line, int graphics);
};

#endif