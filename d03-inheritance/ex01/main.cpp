

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "-------------FRAG-TRAP-----------" <<std::endl;
	FragTrap fragTrapRoberto = FragTrap();
	FragTrap fragTrapHuan("Huan");
	FragTrap fragTrapClone(fragTrapHuan);
	std::cout << "---------------------------------" <<std::endl;
	fragTrapHuan.takeDamage(32);
	fragTrapHuan.takeDamage(4);
	std::cout << "---------------------------------" <<std::endl;
	fragTrapHuan.beRepaired(22);
	fragTrapHuan.beRepaired(33);
	std::cout << "---------------------------------" <<std::endl;
	int i = 6;
	while (--i >= 0)
		fragTrapHuan.vaulthunter_dot_exe("himself");


	std::cout << "---------------------------------" <<std::endl;
	std::cout << "--------------SCAV-TRAP----------" <<std::endl;
	ScavTrap scavTrapAhmed = ScavTrap();
	ScavTrap scavTrapMahmud("Mahmud");
	ScavTrap scavTrapClone(scavTrapMahmud);
	std::cout << "---------------------------------" <<std::endl;
	scavTrapMahmud.takeDamage(32);
	scavTrapMahmud.takeDamage(2);
	std::cout << "---------------------------------" <<std::endl;
	scavTrapMahmud.beRepaired(22);
	scavTrapMahmud.beRepaired(33);
	std::cout << "---------------------------------" <<std::endl;
	i = 5;
	while (--i >= 0)
		scavTrapMahmud.challengeNewcomer("door");
	std::cout << "---------------------------------" <<std::endl;
}