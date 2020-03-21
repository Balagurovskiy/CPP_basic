

#ifndef POEN_HPP
# define POEN_HPP

#include "Victim.hpp"

class Poen : public Victim
{
	public:

		Poen(void);
		Poen(const std::string name);
		Poen(const Poen & p);

		Poen &	operator = (Poen const & p);

		void	getPolymorphed() const;
		
		virtual ~Poen();
};

std::ostream &	operator << (std::ostream & os, Poen const & p);

#endif