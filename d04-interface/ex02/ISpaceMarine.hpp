



#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

#include <iostream>

class ISpaceMarine
{
	public:

		virtual ISpaceMarine* clone() const = 0;

		virtual void battleCry() const = 0;
		virtual void rangedAttack() const = 0;
		virtual void meleeAttack() const = 0;

		virtual ~ISpaceMarine() {}
};

#endif
