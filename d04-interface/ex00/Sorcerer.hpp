

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer
{
	private:

		std::string		_name;
		std::string		_title;

		Sorcerer();

	public:

		Sorcerer(const std::string name, const std::string title);
		Sorcerer(const Sorcerer & s);

		Sorcerer &	operator = (Sorcerer const & s);

		std::string		getName() const;
		void			changeName(std::string const name);
		std::string		getTitle() const;
		void			changeTitle(std::string const value);

		void			polymorph(Victim const & v) const;
		void			polymorph(Peon const & p) const;
		void			polymorph(Poen const & p) const;

		~Sorcerer();
};

std::ostream &	operator << (std::ostream & os, Sorcerer const & s);

#endif
