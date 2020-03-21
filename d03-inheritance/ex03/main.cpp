

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

int	main(void)
{
	NinjaTrap ninjaHokage("Hokage");
	
	std::cout << std::endl;
	FragTrap fragTrap("Meow");

	std::cout << std::endl;
	ScavTrap scavTrap("SCT-42dF");

	std::cout << std::endl;
	ClapTrap clapTrap("Genadiy");

	std::cout << std::endl;
	std::cout << std::endl;

	ninjaHokage.ninjaShoebox(fragTrap);
	ninjaHokage.ninjaShoebox(scavTrap);
	ninjaHokage.ninjaShoebox(clapTrap);
	ninjaHokage.ninjaShoebox(ninjaHokage);

	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}