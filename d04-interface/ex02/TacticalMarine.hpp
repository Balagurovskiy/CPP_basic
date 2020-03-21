

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	public:

		TacticalMarine();
		TacticalMarine(const TacticalMarine & obj);

		TacticalMarine &	operator = (TacticalMarine const & obj);

		virtual TacticalMarine*	clone() const;

		virtual void	battleCry() const;
		virtual void	rangedAttack() const;
		virtual void	meleeAttack() const;

		virtual ~TacticalMarine();

};

#endif
