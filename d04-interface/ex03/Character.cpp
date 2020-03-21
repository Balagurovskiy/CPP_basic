
#include "Character.hpp"

Character::Character(void){
    int i = _max_materias;

    _name = "Character";
    while (--i >= 0)
        _materia[i] = NULL;
}
Character::Character(std::string const &name){
    int i = _max_materias;

    _name = name;
    while (--i >= 0)
        _materia[i] = NULL;
}
Character::Character(Character & obj){
    *this = obj;
}
Character::~Character(void){
    deleteAllMateria();
}

//------------------------------------------------
Character & Character::operator=(Character const &c){
    int i = _max_materias;

    _name = c.getName();
    deleteAllMateria();
    while (--i >= 0)
        _materia[i] = c._materia[i];
    return (*this);
}

//------------------------------------------------
std::string const 	& Character::getName() const{
    return (_name);
}
//------------------------------------------------
void        Character::deleteAllMateria(){
    int i = _max_materias;

    while (--i >= 0) {
        if (_materia[i]) {
            delete _materia[i];
        }
    }
}

void 		Character::equip(AMateria* m){
    int i = 0;
    while (i < _max_materias){
        if (_materia[i] == m)
            return ;
        i++;
    }
    i = 0;
    while (i < _max_materias){
        if (_materia[i] == NULL){
            _materia[i] = m;
            break;
        }
        i++;
    }
}

void 		Character::unequip(int i){
    if (i >= _max_materias)
        return ;
    if (i < 0)
        return ;
    _materia[i] = NULL;
}
void 		Character::use(int i, ICharacter& target){
    if (i >= _max_materias)
        return ;
    if (i < 0)
        return ;
    if (_materia[i] == NULL)
        return ;
    _materia[i]->use(target);
}
