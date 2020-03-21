

#include <iostream>

int		main(void){
	std::string brain = "HI THIS IS BRAIN";
	std::string *p_brain = &brain;
	std::string &r_brain = brain;

	std::cout << " pointer : " << *p_brain << std::endl;
	std::cout << " reference : " << r_brain << std::endl;
	return (0);
}