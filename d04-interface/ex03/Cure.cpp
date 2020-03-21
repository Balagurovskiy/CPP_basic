
#include "Cure.hpp"

Cure::Cure(void){
    _type = "Cure";
    _xp = 0;
}
Cure::Cure(std::string const &type) : AMateria(type){

}
Cure::Cure(Cure &obj){
    *this = obj;
}

Cure::~Cure(void){

}
Cure & Cure::operator=(Cure const &r){
    _type = r.getType();
    _xp = r.getXP();
    return (*this);
}

void     Cure::use_msg(ICharacter & target){
    std::cout << "* heals " << target.getName() << "'s wounds' *" << std::endl;
}
Cure*	Cure::clone(void) const {
    return (new Cure("Cloned Cure"));
}