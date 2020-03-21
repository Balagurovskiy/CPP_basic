/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firewizard <firewizard@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:08:41 by igaliuk           #+#    #+#             */
/*   Updated: 2019/06/24 20:22:32 by firewizard       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	setHitPoints(100);
	setMaxHitPoints(100);
	setMaxEnergyPoints(100);
	setEnergyPoints(100);
	setLevel(1);
	setName("Rodriges");
	setRangedAttackDamage(10);
	setMeleeAttackDamage(20);	
	setArmorDamageReductions(5);
	std::cout << "New ClapTrap! Wow much Trap so Clap !" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
{
	setHitPoints(100);
	setMaxHitPoints(100);
	setMaxEnergyPoints(100);
	setEnergyPoints(100);
	setLevel(1);
	setName(name);
	setRangedAttackDamage(10);
	setMeleeAttackDamage(20);	
	setArmorDamageReductions(5);
	std::cout << "ClapTrap "<< _name << "! ";
	std::cout << "Wow much Trap so Clap !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & obj)
{
	*this = obj;
}

ClapTrap &	ClapTrap::operator = (ClapTrap const & obj)
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
	std::cout << "Cloning ClapTrap... "<< _name << " came in this world !" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << this->getName() << " destroing ClapTrap" << std::endl;
}
//============================================================

void	ClapTrap::rangedAttack(std::string const & target) const
{
	std::cout << this->getName() << " : Baang ! Bang ! ..." << target << " damaged on " << _rangedAttackDamage << " ! \n\tWow ! Youre not dead ?" << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target) const
{
	std::cout << this->getName() << " : hits " << target << " with a knife  * " << _meleeAttackDamage << " damage * !  \n\tRrrrgh..this isnt working !" << std::endl;
}


void	ClapTrap::takeDamage(unsigned int dmg)
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

void	ClapTrap::beRepaired(unsigned int rep)
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

//============================================================
int		ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

void	ClapTrap::setHitPoints(int const value)
{
	this->_hitPoints = value;
}

int		ClapTrap::getMaxHitPoints() const
{
	return (this->_maxHitPoints);
}

void	ClapTrap::setMaxHitPoints(int const value)
{
	this->_maxHitPoints = value;
}

int		ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

void	ClapTrap::setEnergyPoints(int const value)
{
	this->_energyPoints = value;
}

int		ClapTrap::getMaxEnergyPoints() const
{
	return (_maxEnergyPoints);
}

void	ClapTrap::setMaxEnergyPoints(int const value)
{
	this->_maxEnergyPoints = value;
}

int		ClapTrap::getLevel() const
{
	return (this->_level);
}

void	ClapTrap::setLevel(int const value)
{
	this->_level = value;
}

std::string		ClapTrap::getName() const
{
	return (this->_name);
}

void	ClapTrap::setName(std::string const value)
{
	this->_name = value;
}

int		ClapTrap::getMeleeAttackDamage() const
{
	return (this->_meleeAttackDamage);
}

void	ClapTrap::setMeleeAttackDamage(int const value)
{
	this->_meleeAttackDamage = value;
}

int		ClapTrap::getRangedAttackDamage() const
{
	return (this->_rangedAttackDamage);
}

void	ClapTrap::setRangedAttackDamage(int const value)
{
	this->_rangedAttackDamage = value;
}

int		ClapTrap::getArmorDamageReductions() const
{
	return (this->_armorDamageReductions);
}

void	ClapTrap::setArmorDamageReductions(int const value)
{
	this->_armorDamageReductions = value;
}