
#include "Brain.hpp"

Brain::Brain(void){

	return ;
}

Brain::~Brain(void){

	return ;
}

std::string Brain::identify(){
	std::stringstream hex;

	hex << std::hex << this;

	return (hex.str());
}