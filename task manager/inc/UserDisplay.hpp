#include "DisplayClass.hpp"

class UserDisplay : public DisplayClass
{
public:
	UserDisplay();
	UserDisplay(UserDisplay const &copy);
	~UserDisplay();
	UserDisplay &operator=(const UserDisplay &copy);

	void		setLocation();
	void		setText();
	void		draw(std::vector<std::string> line, int graphics);

};
