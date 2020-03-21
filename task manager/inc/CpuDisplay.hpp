#include "DisplayClass.hpp"

class CpuDisplay : public DisplayClass
{
public:
	CpuDisplay();
	CpuDisplay(CpuDisplay const &copy);
	~CpuDisplay();

	CpuDisplay &operator=(const CpuDisplay &copy);

	void		setLocation();
	void		setText();
	void		draw(std::vector<std::string> line, int graphic);

	int max;
};
