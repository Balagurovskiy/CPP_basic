

#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
	public:

		Peon(void);
		Peon(const std::string name);
		Peon(const Peon & p);

		Peon &	operator = (Peon const & p);

		void	getPolymorphed() const;
		
		virtual ~Peon();
};

std::ostream &	operator << (std::ostream & os, Peon const & p);

#endif