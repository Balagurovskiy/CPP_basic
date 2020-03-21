

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int	main(void)
{
	std::cout << "\n-------------init super trap-----------" <<std::endl;
	NinjaTrap nTrap("Target for ninja spec attack");
	SuperTrap superTrap1 = SuperTrap("Pickachu");
	SuperTrap superTrap = superTrap1;

	std::cout << "\n-------------SuperTrap stats-----------" <<std::endl;
	std::cout << "hp: " << superTrap.getMaxHitPoints() <<std::endl;
	std::cout << "energy: " << superTrap.getMaxEnergyPoints()<<std::endl;
	std::cout << "m dmg: " << superTrap.getMeleeAttackDamage()<<std::endl;
	std::cout << "r dmg: " << superTrap.getRangedAttackDamage()<<std::endl;
	std::cout << "def: " << superTrap.getArmorDamageReductions()<<std::endl;

	std::cout << "\n-------------SuperTrap range attack-----------" <<std::endl;
	superTrap.rangedAttack("range target");

	std::cout << "\n-------------SuperTrap melle attack-----------" <<std::endl;
	superTrap.meleeAttack("melee target");

	std::cout << "\n-------------SuperTrap spec Frag dot exe-----------" <<std::endl;
	superTrap.vaulthunter_dot_exe("vaulthunter");

	std::cout << "\n-------------SuperTrap spec Ninja Shoebox-----------" <<std::endl;
	superTrap.ninjaShoebox(nTrap);

	std::cout << "\n-------------destr-----------" <<std::endl;
	
	return 0;
}