
#include "AMateria.hpp"


AMateria::AMateria(void){
    _type = "materia_type";
    _xp = 0;
}
AMateria::AMateria(std::string const &type){
    _type = type;
    _xp = 0;
}
AMateria::AMateria(AMateria &obj){
    *this = obj;
}

AMateria::~AMateria(void){

}
AMateria & AMateria::operator=(AMateria const &r){
    _type = r.getType();
    _xp = r.getXP();
    return (*this);
}

std::string const & AMateria::getType(void) const{
    return (_type);
}
unsigned int	AMateria::getXP(void) const{
    return (_xp);
}

void			AMateria::use(ICharacter& target){
    _xp += 10;
    use_msg(target);
}
