
#include "Human.hpp"
#include "Brain.hpp"

Human::Human(void){

	return ;
}

Human::~Human(void){

	return ;
}

Brain 		&Human::getBrain(){
	return (this->_brain);
}

std::string Human::identify(){
	return (this->_brain.identify());
}