
#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class	SuperTrap : virtual public FragTrap, virtual public NinjaTrap
{

	public:

		SuperTrap(void);
		SuperTrap(std::string name);
		SuperTrap(const SuperTrap &obj);
		~SuperTrap(void);
		SuperTrap &operator=(SuperTrap const &r);

		// virtual void	rangedAttack(std::string const & target) const;
		// virtual void	meleeAttack(std::string const & target) const;
}; 

#endif