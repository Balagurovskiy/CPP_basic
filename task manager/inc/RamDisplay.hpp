#ifndef RAMDISPLAY_HPP
# define RAMDISPLAY_HPP

#include "DisplayClass.hpp"

class RamDisplay : public DisplayClass
{
public:
	RamDisplay();
	RamDisplay(RamDisplay const &copy);
	~RamDisplay();
	RamDisplay &operator=(const RamDisplay &copy);

	void		setLocation();
	void		setText();
	void		draw(std::vector<std::string> line, int graphics);

	int max;
};

#endif