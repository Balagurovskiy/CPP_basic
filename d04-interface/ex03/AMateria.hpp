
#ifndef AMATERIA_H
# define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class	AMateria
{
	public:

		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria &obj);
		virtual ~AMateria(void);
		AMateria &operator=(AMateria const &r);

		std::string const		&getType(void) const; //Returns the materia type
		unsigned int			getXP(void) const; //Returns the Materia s XP

		virtual AMateria*		clone(void) const = 0;
		virtual void			use(ICharacter& target);

	protected:
		std::string		_type;
		unsigned int	_xp;

        virtual void            use_msg(ICharacter & target) = 0;
};

#endif
