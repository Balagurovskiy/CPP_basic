
#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
	public:

		AssaultTerminator();
		AssaultTerminator(const AssaultTerminator & obj);

		AssaultTerminator &	operator = (AssaultTerminator const & obj);

		virtual AssaultTerminator*	clone() const;

		virtual void	battleCry() const;
		virtual void	rangedAttack() const;
		virtual void	meleeAttack() const;

		virtual ~AssaultTerminator();

};

#endif

