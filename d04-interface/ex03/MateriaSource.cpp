
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void){
    int i = _max_materias;

    while (--i >= 0)
        _materia[i] = NULL;
}
MateriaSource::MateriaSource(MateriaSource &obj){
    *this = obj;
}
MateriaSource::~MateriaSource(void){
    deleteAllMateria();
}
MateriaSource & MateriaSource::operator=(MateriaSource const & obj){
    int i = _max_materias;

    deleteAllMateria();
    while (--i >= 0)
        _materia[i] = obj._materia[i];
    return (*this);
}
//------------------------------------------------
void        MateriaSource::deleteAllMateria(){
    int i = _max_materias;
    std::cout<<std::endl;
    while (--i >= 0) {
        if (_materia[i]) {
            delete _materia[i];
        }
    }
}
void 		MateriaSource::learnMateria(AMateria * m){
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
bool        MateriaSource::equalType(AMateria * materia, std::string const & type){
    if (materia){
        int i = 0;

        if ( materia->getType().size() != type.size())
            return false;
        while (i < materia->getType().size()){
            char matType = tolower(materia->getType()[i]);
            char inType = tolower(type[i]);
            if (matType != inType)
                return false;
            i++;
        }
        return (true);
    }
    return (false);
}
AMateria *  MateriaSource::createMateria(std::string const & type){
    int i = _max_materias;

    while (--i >= 0) {

        if (equalType(_materia[i], type))
            return (_materia[i]->clone());
    }
    return (0);
}
    