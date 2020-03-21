

#ifndef PONY_H
# define PONY_H

#include <iostream>
// #include <string>

class	Pony {

	public: 

		Pony(std::string n,  bool a); 
		~Pony(void);

		std::string 	name;
		bool			ability;
};

#endif