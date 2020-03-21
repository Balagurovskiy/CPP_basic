
#include "Ice.hpp"

Ice::Ice(void){
    _type = "Ice";
    _xp = 0;
}
Ice::Ice(std::string const &type) : AMateria(type){

}
Ice::Ice(Ice &obj){
    *this = obj;
}

Ice::~Ice(void){

}
Ice & Ice::operator=(Ice const &r){
    _type = r.getType();
    _xp = r.getXP();
    return (*this);
}

void     Ice::use_msg(ICharacter & target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
Ice*	Ice::clone(void) const {
    return (new Ice("Cloned Ice"));
}