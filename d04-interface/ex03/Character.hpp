
#ifndef CHARACTER_H
# define CHARACTER_H

#include <iostream>
#include "AMateria.hpp"

class	Character : public ICharacter
{

public:

	Character(void);
	Character(std::string const &name);
	Character(Character &obj);
	~Character(void);
	Character &operator=(Character const &r);


	std::string const 	&getName() const;
	void 				equip(AMateria* obj);
	void 				unequip(int i);
	void 				use(int i, ICharacter& target);

private:
    static int const _max_materias = 4;

	AMateria		*_materia[_max_materias];
	std::string	    _name;

	void            deleteAllMateria(void);


};

#endif
