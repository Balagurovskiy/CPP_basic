

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>

class ScavTrap
{
	private:

		int					_hitPoints;
		int					_maxHitPoints;
		int					_energyPoints;
		int					_maxEnergyPoints;
		int					_level;
		std::string			_name;
		int					_meleeAttackDamage;
		int					_rangedAttackDamage;
		int					_armorDamageReductions;

	public:

		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap & sTrap);

		ScavTrap &	operator = (ScavTrap const & obj);

		void	rangedAttack(std::string const & target) const;
		void	meleeAttack(std::string const & target) const;
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	challengeNewcomer(std::string const & target);

		
		void	setHitPoints(int const value);
		void	setMaxHitPoints(int const value);
		void	setEnergyPoints(int const value);
		void	setMaxEnergyPoints(int const value);
		void	setLevel(int const value);
		void	setName(std::string const value);
		void	setMeleeAttackDamage(int const value);
		void	setRangedAttackDamage(int const value);
		void	setArmorDamageReductions(int const value);

		int		getHitPoints() const;
		int		getMaxHitPoints() const;
		int		getEnergyPoints() const;
		int		getMaxEnergyPoints() const;
		int		getLevel() const;
		std::string		getName() const;
		int		getMeleeAttackDamage() const;
		int		getRangedAttackDamage() const;
		int		getArmorDamageReductions() const;


		~ScavTrap();
};

#endif