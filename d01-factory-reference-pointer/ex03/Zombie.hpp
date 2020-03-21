
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
// #include <string>

class	Zombie {

	public: 

		Zombie(void); 
		~Zombie(void);

		void announce();

		std::string 	_name;
		std::string		_type;
		
};

#endif