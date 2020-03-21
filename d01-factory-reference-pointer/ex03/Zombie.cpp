
#include "Zombie.hpp"

Zombie::Zombie(void){
	this->_name = "Zombie";
	this->_type = "Arrrhh";
	return ;
}

Zombie::~Zombie(){
	std::cout << this->_name << " has disapeared." << std::endl;
	return ;
}

void	Zombie::announce(){
	std::cout << "<" << this->_name << " (" << this->_type << ")" <<  "> Braiiiiiiinnnssss..." <<std::endl;
}