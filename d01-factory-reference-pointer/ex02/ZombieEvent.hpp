
#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

#include "Zombie.hpp"

class	ZombieEvent {

	public: 

		ZombieEvent(void); 
		~ZombieEvent(void);		

		void	setZombieType(std::string type);
		Zombie	*newZombie(std::string name);
		Zombie	*randomChump();

	private:
		std::string		_type;
		int				_randomEntry;
};

#endif