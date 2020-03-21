
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string name, const std::string title){
	this->_name = name;
	this->_title = title;
	std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer & s){
	*this = s;
}

Sorcerer &	Sorcerer::operator = (Sorcerer const & s){
	changeName(s.getName());
	changeTitle(s.getTitle());
	return (*this);
}

Sorcerer::~Sorcerer(){
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - 
void Sorcerer::changeName(std::string const name){
	this->_name = name;
}
std::string Sorcerer::getName() const{
	return(this->_name);
}
void Sorcerer::changeTitle(std::string const title){
	this->_title = title;
}
std::string Sorcerer::getTitle() const{
	return(this->_title);
}
//- - - - - - - - - - - - - - - - - - - - - - - - - 
void Sorcerer::polymorph(Victim const & v) const{
	v.getPolymorphed();
}
void Sorcerer::polymorph(Peon const & p) const{
	p.getPolymorphed();
}
void Sorcerer::polymorph(Poen const & p) const{
	p.getPolymorphed();
}
//- - - - - - - - - - - - - - - - - - - - - - - - - 
std::ostream &	operator << (std::ostream & os, Sorcerer const & s){
	os << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies !" << std::endl;
	return (os);
}
