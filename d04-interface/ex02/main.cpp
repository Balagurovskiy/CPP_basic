#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
//
	ISquad* vlc =  new Squad;

	vlc->push(bob);
	vlc->push(jim);

	std::cout  << std::endl;

	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout  << std::endl;

	delete vlc;

//	std::cout  << std::endl;

//	system("leaks a.out");
	return 0;

}
