

#include "Squad.hpp"

Squad::Squad(){
	_count = 0;
	_squad = NULL;
}
Squad::Squad(const Squad & s){
	_count = 0;
	_squad = NULL;
	*this = s;
}
Squad &	Squad::operator = (Squad const & s){
	t_unit * copy_squad = NULL;
	if (this == &s)
		return (*this);
	freeSquad();
	std::cout << "-+-" << std::endl;
	copy_squad = s._squad;
	while(copy_squad) {
		push(copy_squad->_unit->clone());
		copy_squad = copy_squad->next;
	}
	_count = s.getCount();
	return (*this);
}
Squad::~Squad(){
	freeSquad();
}

//**********************************************
int				Squad::getCount() const{
	return (_count);
}
ISpaceMarine *	Squad::getUnit(int N) const{
	t_unit *	squad = NULL;

	squad = _squad;
	if (!squad)
		return (NULL);
	while(squad && squad->next && N-- > 0)
		squad = squad->next;
	return (squad->_unit);
}
//**********************************************
int				Squad::push(ISpaceMarine * spaceMarine){
	t_unit *	squad = NULL;

	if(unitExists(spaceMarine) || !spaceMarine)
		return (_count);
	squad = getLastSquadUnit();
	if (squad)
		squad->next = newSquadUnit(spaceMarine);
	else
		_squad = newSquadUnit(spaceMarine);
	_count++;
	return (_count);
}
// * * * * * * * * * * * * * * * * * * * * * * * *

t_unit *		Squad::newSquadUnit(ISpaceMarine* spaceMarine){
	t_unit *newnode = NULL;

	newnode = new t_unit;
	newnode->_unit = spaceMarine;
	newnode->next = NULL;
	return (newnode);
}

t_unit *		Squad::getLastSquadUnit(){
	t_unit *	squad = NULL;

	squad = _squad;
	while(squad && squad->next)
		squad = squad->next;
	return (squad);
}

bool 			Squad::unitExists(ISpaceMarine *spaceMarine){
	t_unit *	squad = NULL;

	squad = _squad;
	while(squad){
		if (squad->_unit == spaceMarine)
			return (true);
		squad = squad->next;
	}

	return (false);
}
void 			Squad::freeSquad(){
	t_unit *	currentUnitToDel = NULL;
	while(_squad){
		currentUnitToDel = _squad;
		_squad = _squad->next;
		if (currentUnitToDel && currentUnitToDel->_unit)
			delete currentUnitToDel->_unit;
		if (currentUnitToDel)
			delete currentUnitToDel;
	}

}