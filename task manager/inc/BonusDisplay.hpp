#ifndef BONUSDISPLAY_HPP
# define BONUSDISPLAY_HPP

#include "DisplayClass.hpp"

class BonusDisplay : public DisplayClass
{
public:
	BonusDisplay();
	BonusDisplay(BonusDisplay const &copy);
	~BonusDisplay();

	BonusDisplay &operator=(const BonusDisplay &copy);

	void		setLocation();
	void		setText();
	void		draw(std::vector<std::string> line, int graphics);
};

#endif