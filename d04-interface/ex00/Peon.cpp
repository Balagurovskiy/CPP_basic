
#include "Peon.hpp"

Peon::Peon(){
	changeName("Peon");
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const std::string name)  : Victim(name){

	changeName(name);
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon & p) {
	*this = p;
	std::cout << "Zog zog." << std::endl;
}

Peon &	Peon::operator = (Peon const & p){
	changeName(p.getName());
	return (*this);
}

Peon::~Peon(){
	std::cout << "Bleuark..." << std::endl;
}

//- - - - - - - - - - - - - - - - - - - - - - - - - 
void	Peon::getPolymorphed() const{
	std::cout << getName() << " has been turned into a pink pony !" << std::endl;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - 
std::ostream &	operator << (std::ostream & os, Peon const & p){
	os << "I'm " << p.getName() << " and I like otters !" << std::endl;
	return (os);
}