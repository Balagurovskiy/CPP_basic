
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
{
	setHitPoints(60);
	setMaxHitPoints(60);
	setMaxEnergyPoints(120);
	setEnergyPoints(120);
	setLevel(1);
	setName("Naruto");
	setRangedAttackDamage(5);
	setMeleeAttackDamage(60);	
	setArmorDamageReductions(0);
	std::cout << "日本にほんでは" << std::endl;
}

NinjaTrap::NinjaTrap(const std::string name)
{
	setHitPoints(60);
	setMaxHitPoints(60);
	setMaxEnergyPoints(120);
	setEnergyPoints(120);
	setLevel(1);
	setName(name);
	setRangedAttackDamage(5);
	setMeleeAttackDamage(60);	
	setArmorDamageReductions(0);

	std::cout << _name << " ! ";
	std::cout << "日本にほんでは、近頃ちかごろ多お" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap & trap)
{
	*this = trap;	
}

NinjaTrap &	NinjaTrap::operator = (NinjaTrap const & trap)
{
	ClapTrap::operator=(trap);
	std::cout << _name << " :" << std::endl;
	std::cout << "\tおくの人ひ  る。特" << std::endl;
	return (*this);
}

NinjaTrap::~NinjaTrap()
{
	std::cout << getName() << " 子こど " << std::endl;
}

// void	FragTrap::rangedAttack(std::string const & target) const
// {
// 	std::cout << this->getName() << " : suriken attack on " << target << " cause massive splash damage -" << _rangedAttackDamage <<  std::endl;
// }

void	NinjaTrap::meleeAttack(std::string const & target) const
{
		std::cout << this->getName() << " : 'Omaevo ma shinda eru' ! ..." << target << " -'nani?' ----" << getMeleeAttackDamage() << " damage" << std::endl;
}


void	NinjaTrap::ninjaShoebox(FragTrap & trap) const
{
	std::cout << this->getName() << ": ん 問題 もん だ ! (" << trap.getName() << ")" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap & trap) const
{
	std::cout << this->getName() << ": について ! (" << trap.getName() << ")" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap & trap) const
{
	std::cout << this->getName() << ": 。特とくに東京 ! (" << trap.getName() << ")" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap & trap) const
{
	std::cout << this->getName() << ": がないので、\n\t子こどもをので、\n\t子こどもを保育園\n\tほいくえんに入い " << std::endl;
}