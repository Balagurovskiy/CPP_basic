

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_name = "Roberto";
	this->_meleeAttackDamage = 30;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReductions = 5;

	std::cout << "Did you find the Vault yet ?" << std::endl;
}

FragTrap::FragTrap(const std::string name)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_name = name;
	this->_meleeAttackDamage = 30;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReductions = 5;

	std::cout << _name << " ! ";
	std::cout << "Sure is lonely around here" << std::endl;
}

FragTrap::FragTrap(const FragTrap & trap)
{
	*this = trap;	
}

FragTrap &	FragTrap::operator = (FragTrap const & trap)
{
	ClapTrap::operator=(trap);
	std::cout << _name << " :" << std::endl;
	std::cout << "\tWanna hear a new dubstep song I wrote ? Wub ! Wub *beatboxing*" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << this->getName() << " : OH my GOD, Im leaking ! Ahhh There is oil everywhere...I can see...the code..." << std::endl;
}

void	FragTrap::rangedAttack(std::string const & target) const
{
	std::cout << this->getName() << " : Baang ! Bang ! ..." << target << " was damaged on " << _rangedAttackDamage << " ! \n\tWow ! Youre not dead ?" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string attacks[] = {
		"Did you fire six shots, or five ?", 
		"Are you still alive ?",		
		"Avada kedavra !", 
		"Ya feeling lucky, punk ?", 
		"Come over here, Ill gnaw your legs off !"
		};
	void (ClapTrap::*attackMode[])(std::string const & target) const = {&ClapTrap::rangedAttack, &ClapTrap::meleeAttack};

	std::cout << this->getName() << ":";
	if (this->getEnergyPoints() - 25 >= 0){
		this->setEnergyPoints(this->getEnergyPoints() - 25);
		std::cout << "\t Energy[" << this->getEnergyPoints() << "] \n\t" << attacks[std::rand() % 5] << std::endl;
		(this->*attackMode[std::rand() % 2])(target);
		std::cout << std::endl;
	}else{
		std::cout << "\t Ahem, ahem.Whats going on ? Did i break something ?? " << std::endl;
	}	
}
