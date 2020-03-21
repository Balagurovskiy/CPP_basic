#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{

    public:

        MateriaSource(void);
        MateriaSource(MateriaSource &obj);
        virtual ~MateriaSource(void);
        MateriaSource &operator=(MateriaSource const &r);

        void 		learnMateria(AMateria*);
        AMateria	*createMateria(std::string const & type);

    private:
        static int const _max_materias = 4;
        AMateria	*_materia[_max_materias];

        void            deleteAllMateria(void);
        bool            equalType(AMateria * m, std::string const & type);
};

#endif