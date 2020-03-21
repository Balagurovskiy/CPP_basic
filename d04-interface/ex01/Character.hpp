
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Enemy.hpp"
#include "AWeapon.hpp"

class Character
{
	protected:

		std::string	_name;

		AWeapon		*_weapon;
		int			_AP;

	public:

		Character();
		Character(std::string const & name);
		Character(const Character & c);

		Character &	operator = (Character const & c);

		std::string const &		getName() const;
		AWeapon *				getWeapon() const;
		int						getAP() const;
		
		void					attack(Enemy* target);
		void					recoverAP();
		void					equip(AWeapon* weapon);

		~Character();
};

std::ostream &	operator << (std::ostream & o, Character const & c);

#endif
