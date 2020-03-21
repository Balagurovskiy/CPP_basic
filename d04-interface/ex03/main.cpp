#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* zaz = new Character("zaz");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    zaz->equip(tmp);
    tmp = src->createMateria("cure");
    zaz->equip(tmp);
//    zaz->equip(tmp);
//    zaz->equip(tmp);
//    zaz->equip(tmp);
//    zaz->equip(tmp);
    ICharacter* bob = new Character("bob");

    zaz->use(0, *bob);
    zaz->use(1, *bob);
//    zaz->use(3, *bob);
//    zaz->use(11, *bob);
//    zaz->unequip(3);
//    zaz->use(0, *bob);
//    zaz->use(1, *bob);
//    zaz->unequip(1);
//    zaz->use(0, *bob);
//    zaz->use(1, *bob);
    delete bob;
    delete zaz;
    delete src;
    return 0;
}

//unequip