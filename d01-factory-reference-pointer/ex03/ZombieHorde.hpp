
#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

#include "Zombie.hpp"

class	ZombieHorde {
	public:
		ZombieHorde(int n);
		~ZombieHorde(void);

		void		announce();

	private:
		void		initHorde();
		std::string	randomName(int k);

		Zombie* 	_horde;
		int			_horde_amount;

		int 		_random_entry;
};

#endif