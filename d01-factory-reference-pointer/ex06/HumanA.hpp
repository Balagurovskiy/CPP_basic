
#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class	HumanA {

	public: 

		HumanA(std::string name, Weapon &weapon); 
		~HumanA(void);


		void	attack();
	private:
		Weapon		&_weapon;
		std::string _name;

};

#endif