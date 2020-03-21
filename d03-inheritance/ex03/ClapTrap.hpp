/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firewizard <firewizard@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 16:46:19 by igaliuk           #+#    #+#             */
/*   Updated: 2019/06/24 20:34:39 by firewizard       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:

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

		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap & obj);

		ClapTrap &	operator = (ClapTrap const & obj);

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

		void	rangedAttack(std::string const & target) const;
		void	meleeAttack(std::string const & target) const;
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		virtual ~ClapTrap();
};

#endif
