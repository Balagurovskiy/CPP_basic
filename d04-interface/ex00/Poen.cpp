
#include "Poen.hpp"

Poen::Poen(){
	changeName("Poen");
	std::cout << "Wok wok." << std::endl;
}

Poen::Poen(const std::string name)  : Victim(name){

	changeName(name);
	std::cout << "Wok wok." << std::endl;
}

Poen::Poen(const Poen & p) {
	*this = p;
	std::cout << "Wok wok." << std::endl;
}

Poen &	Poen::operator = (Poen const & p){
	changeName(p.getName());
	return (*this);
}

Poen::~Poen(){
	std::cout << "Aulark..." << std::endl;
}

//- - - - - - - - - - - - - - - - - - - - - - - - - 
void	Poen::getPolymorphed() const{
	std::cout << getName() << " has been turned into ... JOHN CIEANA ! TA TA RA RAAAM !" << std::endl;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - 
std::ostream &	operator << (std::ostream & os, Poen const & p){
	os << "I'm " << p.getName() << " and I like otters !" << std::endl;
	return (os);
}