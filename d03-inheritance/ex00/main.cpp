

#include "FragTrap.hpp"

int	main(void)
{
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
}