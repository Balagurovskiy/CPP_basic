

#include "Victim.hpp"

Victim::Victim(){
	changeName("Victim");
	std::cout << "Some random victim called " + getName() + " just popped !" << std::endl;
}

Victim::Victim(const std::string name){
	changeName(name);
	std::cout << "Some random victim called " + getName() + " just popped !" << std::endl;
}

Victim::Victim(const Victim & v){
	*this = v;
}

Victim &	Victim::operator = (Victim const & v){
	changeName(v.getName());
	return (*this);
}

Victim::~Victim(){
	std::cout << "Victim " + getName() +" just died for no apparent reason !" << std::endl;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - 
void Victim::changeName(std::string const name){
	this->_name = name;
}
std::string Victim::getName() const{
	return(this->_name);
}
//- - - - - - - - - - - - - - - - - - - - - - - - - 
void	Victim::getPolymorphed() const{
	std::cout << getName() << " has been turned into a cute little sheep !" << std::endl;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - 
std::ostream &	operator << (std::ostream & os, Victim const & v){
	os << "I'm " << v.getName() << " and I like otters !" << std::endl;
	return (os);
}