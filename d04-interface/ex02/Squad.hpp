

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include <iostream>
#include "ISquad.hpp"

typedef struct		s_unit
{
	ISpaceMarine	*_unit;
	s_unit			*next;

} 					t_unit;

class Squad : public ISquad
{

private:
	t_unit *	newSquadUnit(ISpaceMarine* spaceMarine);
	t_unit *	getLastSquadUnit();
	void 		freeSquad();
	bool 		unitExists(ISpaceMarine *spaceMarine);

protected:
	int			_count;
	t_unit *	_squad;

public:
	Squad();
	Squad(const Squad & s);

	Squad &	operator = (Squad const & s);

	virtual int				getCount() const;
	virtual ISpaceMarine*	getUnit(int) const;

	virtual int		push(ISpaceMarine*);

	virtual ~Squad();
};

#endif