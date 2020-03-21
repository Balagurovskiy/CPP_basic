

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class NinjaTrap: virtual public ClapTrap
{
	public:

		NinjaTrap();
		NinjaTrap(const std::string name);
		NinjaTrap(const NinjaTrap & trap);

		NinjaTrap &	operator = (NinjaTrap const & trap);


		virtual void	meleeAttack(std::string const & target) const;


		void	ninjaShoebox(FragTrap & trap) const;
		void	ninjaShoebox(ScavTrap & trap) const;
		void	ninjaShoebox(ClapTrap & trap) const;
		void	ninjaShoebox(NinjaTrap & trap) const;

		~NinjaTrap();
};

#endif