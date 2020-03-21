

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_name = "Ahmed";
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReductions = 3;

	std::cout << "Scav is somewhere here" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_name = name;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReductions = 3;

	std::cout << _name << " ! ";
	std::cout << "He he he" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & trap)
{
	*this = trap;	
}

ScavTrap &	ScavTrap::operator = (ScavTrap const & trap)
{
	ClapTrap::operator=(trap);

	std::cout << _name << " :" << std::endl;
	std::cout << "\t Fresh scav clone is here" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << this->getName() << " : I'll get you next time!" << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target) const
{
	std::string attacks[] = {
		"go 1 vs 1 na rune !", 
		"You are doomed !",		
		"Havent you surrender yet ?", 
		"Ti kto takoi ?", 
		"Asta la vista babe !"
		};

	std::cout << this->getName() << ":";
	std::cout <<  attacks[std::rand() % 5] << std::endl;
	std::cout << std::endl;
}
