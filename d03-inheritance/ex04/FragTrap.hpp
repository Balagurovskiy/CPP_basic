
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:

		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap & obj);

		FragTrap &	operator = (FragTrap const & obj);


		virtual void	rangedAttack(std::string const & target) const;

		void	vaulthunter_dot_exe(std::string const & target);

		~FragTrap();
};

#endif
