
#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy
{
	protected:

		int			_hp;
		std::string	_type;

	public:

		Enemy();
		Enemy(int hp, std::string const & type);
		Enemy(const Enemy & obj);

		Enemy &	operator = (Enemy const & o);

		int						getHP() const;
		std::string const &		getType() const;

		virtual void			takeDamage(int damage);

		virtual ~Enemy();
};

#endif