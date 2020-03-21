

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim
{
	protected:

		std::string		_name;

	public:

		Victim(void);
		Victim(const std::string name);
		Victim(const Victim & v);

		Victim &	operator = (Victim const & v);

		std::string		getName() const;
		void			changeName(std::string const name);

		virtual void	getPolymorphed() const;

		virtual ~Victim();
};

std::ostream &	operator << (std::ostream & o, Victim const & v);

#endif