

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

FragTrap::FragTrap(const FragTrap & obj)
{
	*this = obj;	
}

FragTrap &	FragTrap::operator = (FragTrap const & obj)
{
	setHitPoints(obj.getHitPoints());
	setMaxHitPoints(obj.getMaxHitPoints());
	setMaxEnergyPoints(obj.getMaxEnergyPoints());
	setEnergyPoints(obj.getEnergyPoints());
	setLevel(obj.getLevel());
	setName(obj.getName());
	setRangedAttackDamage(obj.getRangedAttackDamage());
	setMeleeAttackDamage(obj.getMeleeAttackDamage());
	setArmorDamageReductions(obj.getArmorDamageReductions());

	std::cout << _name << " :" << std::endl;
	std::cout << "\tWanna hear a new dubstep song I wrote ? Wub ! Wub *beatboxing*" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << this->getName() << " : OH my GOD, Im leaking ! Ahhh There is oil everywhere...I can see...the code..." << std::endl;
}
//============================================================

void	FragTrap::rangedAttack(std::string const & target) const
{
	std::cout << this->getName() << " : Baang ! Bang ! ..." << target << " damaged on " << _rangedAttackDamage << " ! \n\tWow ! Youre not dead ?" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target) const
{
	std::cout << this->getName() << " : hits " << target << " with a knife  * " << _meleeAttackDamage << " damage * !  \n\tRrrrgh..this isnt working !" << std::endl;
}


void	FragTrap::takeDamage(unsigned int dmg)
{
 	int damageThrowArmor;

 	damageThrowArmor = dmg - this->getArmorDamageReductions();
 	if (damageThrowArmor > 0){
 		if (this->getHitPoints() < damageThrowArmor)
 			this->setHitPoints(0);
 		else
 			this->setHitPoints(this->getHitPoints() - damageThrowArmor);
 		std::cout << this->getName() << " : takes " << damageThrowArmor << " damage ! ";
 		std::cout << "   [ " << this->getHitPoints() << "/" << this->getMaxHitPoints() << "]" << std::endl;
 		std::cout << "\tPlease dont shoot me, please dont shoot me !" << std::endl;
 	}else{
 		std::cout << this->getName() << " : takes no damage ! " << std::endl;
 		std::cout << "\tTurning off the optics...they cant see me... " << std::endl;
 	}
}

void	FragTrap::beRepaired(unsigned int rep)
{
	if (rep + this->getHitPoints() > this->getMaxHitPoints())
		this->setHitPoints(this->getMaxHitPoints());
	else
		this->setHitPoints(rep + this->getHitPoints());
	if (rep + this->getEnergyPoints() > this->getMaxEnergyPoints())
		this->setEnergyPoints(this->getMaxEnergyPoints());
	else
		this->setEnergyPoints(rep + this->getEnergyPoints());
	std::cout << _name << " : repaired on " << rep << " points ! " ;
	std::cout << "   [ " << this->getHitPoints() << "/" << this->getMaxHitPoints() << "]" << std::endl;
	std::cout << "\tGood as new, I think. Am I leaking? " << std::endl;
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
	void (FragTrap::*attackMode[])(std::string const & target) const = {&FragTrap::rangedAttack, &FragTrap::meleeAttack};

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

//============================================================
int		FragTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

void	FragTrap::setHitPoints(int const value)
{
	this->_hitPoints = value;
}

int		FragTrap::getMaxHitPoints() const
{
	return (this->_maxHitPoints);
}

void	FragTrap::setMaxHitPoints(int const value)
{
	this->_maxHitPoints = value;
}

int		FragTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

void	FragTrap::setEnergyPoints(int const value)
{
	this->_energyPoints = value;
}

int		FragTrap::getMaxEnergyPoints() const
{
	return (_maxEnergyPoints);
}

void	FragTrap::setMaxEnergyPoints(int const value)
{
	this->_maxEnergyPoints = value;
}

int		FragTrap::getLevel() const
{
	return (this->_level);
}

void	FragTrap::setLevel(int const value)
{
	this->_level = value;
}

std::string		FragTrap::getName() const
{
	return (this->_name);
}

void	FragTrap::setName(std::string const value)
{
	this->_name = value;
}

int		FragTrap::getMeleeAttackDamage() const
{
	return (this->_meleeAttackDamage);
}

void	FragTrap::setMeleeAttackDamage(int const value)
{
	this->_meleeAttackDamage = value;
}

int		FragTrap::getRangedAttackDamage() const
{
	return (this->_rangedAttackDamage);
}

void	FragTrap::setRangedAttackDamage(int const value)
{
	this->_rangedAttackDamage = value;
}

int		FragTrap::getArmorDamageReductions() const
{
	return (this->_armorDamageReductions);
}

void	FragTrap::setArmorDamageReductions(int const value)
{
	this->_armorDamageReductions = value;
}