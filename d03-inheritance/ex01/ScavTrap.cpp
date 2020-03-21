

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

ScavTrap::ScavTrap(const ScavTrap & obj)
{
	*this = obj;	
}

ScavTrap &	ScavTrap::operator = (ScavTrap const & obj)
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
	std::cout << "\t Fresh scav clone is here" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << this->getName() << " : I'll get you next time!" << std::endl;
}
//============================================================

void	ScavTrap::rangedAttack(std::string const & target) const
{
	std::cout << this->getName() << " : put some bullets on " << target << " * " << _rangedAttackDamage << " damage *!" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target) const
{
	std::cout << this->getName() << " : uses his magnificent robot arms to destroy " << target << "  * " << _meleeAttackDamage << " damage * !  " << std::endl;
}


void	ScavTrap::takeDamage(unsigned int dmg)
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

void	ScavTrap::beRepaired(unsigned int rep)
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
	std::cout << "\tGood as new! " << std::endl;
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

//============================================================
int		ScavTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

void	ScavTrap::setHitPoints(int const value)
{
	this->_hitPoints = value;
}

int		ScavTrap::getMaxHitPoints() const
{
	return (this->_maxHitPoints);
}

void	ScavTrap::setMaxHitPoints(int const value)
{
	this->_maxHitPoints = value;
}

int		ScavTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

void	ScavTrap::setEnergyPoints(int const value)
{
	this->_energyPoints = value;
}

int		ScavTrap::getMaxEnergyPoints() const
{
	return (_maxEnergyPoints);
}

void	ScavTrap::setMaxEnergyPoints(int const value)
{
	this->_maxEnergyPoints = value;
}

int		ScavTrap::getLevel() const
{
	return (this->_level);
}

void	ScavTrap::setLevel(int const value)
{
	this->_level = value;
}

std::string		ScavTrap::getName() const
{
	return (this->_name);
}

void	ScavTrap::setName(std::string const value)
{
	this->_name = value;
}

int		ScavTrap::getMeleeAttackDamage() const
{
	return (this->_meleeAttackDamage);
}

void	ScavTrap::setMeleeAttackDamage(int const value)
{
	this->_meleeAttackDamage = value;
}

int		ScavTrap::getRangedAttackDamage() const
{
	return (this->_rangedAttackDamage);
}

void	ScavTrap::setRangedAttackDamage(int const value)
{
	this->_rangedAttackDamage = value;
}

int		ScavTrap::getArmorDamageReductions() const
{
	return (this->_armorDamageReductions);
}

void	ScavTrap::setArmorDamageReductions(int const value)
{
	this->_armorDamageReductions = value;
}