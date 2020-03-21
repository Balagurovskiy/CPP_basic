
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void)
{
	FragTrap ft = FragTrap();
	NinjaTrap nt = NinjaTrap();
	
	setHitPoints(ft.getHitPoints());
	setMaxHitPoints(ft.getMaxHitPoints());
	setMaxEnergyPoints(nt.getMaxEnergyPoints());
	setEnergyPoints(nt.getEnergyPoints());
	setLevel(1);
	setName("Superior Trap");
	setRangedAttackDamage(ft.getRangedAttackDamage());
	setMeleeAttackDamage(nt.getMeleeAttackDamage());	
	setArmorDamageReductions(ft.getArmorDamageReductions());
	std::cout << "New SUPER TRAP!" << std::endl;
}
SuperTrap::~SuperTrap(void)
{
}

SuperTrap::SuperTrap(const std::string name)
{
	FragTrap ft = FragTrap(name);
	NinjaTrap nt = NinjaTrap(name);

	setHitPoints(ft.getHitPoints());
	setMaxHitPoints(ft.getMaxHitPoints());
	setMaxEnergyPoints(nt.getMaxEnergyPoints());
	setEnergyPoints(nt.getEnergyPoints());
	setLevel(1);
	setName(name);
	setRangedAttackDamage(ft.getRangedAttackDamage());
	setMeleeAttackDamage(nt.getMeleeAttackDamage());	
	setArmorDamageReductions(ft.getArmorDamageReductions());
	std::cout << "Super  "<< getName() << " ";
	std::cout << "is ready to burn this world!" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap & obj)
{
	*this = obj;
}

SuperTrap &	SuperTrap::operator = (SuperTrap const & trap)
{
	ClapTrap::operator=(trap);
	std::cout << getName() << " :" << std::endl;
	std::cout << "\tSuper trap was copied ! SUPER x 2 !!!" << std::endl;
	return (*this);
}