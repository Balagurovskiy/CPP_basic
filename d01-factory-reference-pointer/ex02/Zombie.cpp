
#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type){
	this->_name = name;
	this->_type = type;
	this->announce();
	return ;
}

Zombie::~Zombie(){
	std::cout << this->_name << " has disapeared." << std::endl;
	return ;
}

void	Zombie::announce(){
	std::cout << "<" << this->_name << " (" << this->_type << ")" <<  "> Braiiiiiiinnnssss..." <<std::endl;
}