
#ifndef BRAIN_H
# define BRAIN_H

#include "Brain.hpp"

class Human{
	public:
		Human(void);
		~Human(void);

		std::string identify();
		Brain 		&getBrain();
	
	private:
		Brain 		_brain;
};
#endif