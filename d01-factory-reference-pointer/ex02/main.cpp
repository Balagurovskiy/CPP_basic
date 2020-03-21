
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main()
{
	std::cout << "\n:::::: new stack zombie ::::::"<< std::endl;
	Zombie someZombie = Zombie("CaH9", "4etkiy");
	someZombie.announce();

	ZombieEvent zombieEvent = ZombieEvent();
	std::cout << "\n:::::: random heap zombie event ::::::"<< std::endl;
	zombieEvent.setZombieType("Random Assault");
	Zombie *randomZombie = zombieEvent.randomChump();

	zombieEvent.setZombieType("Random Banana");
	Zombie *randomZombie1 = zombieEvent.randomChump();
	Zombie *randomZombie2 = zombieEvent.randomChump();
	Zombie *randomZombie3 = zombieEvent.randomChump();

	std::cout << "\n:::::: new heap zombie event ::::::"<< std::endl;
	zombieEvent.setZombieType("Alcoholic");
	Zombie *petrZombie = zombieEvent.newZombie("Petrovich");

	std::cout << std::endl;
	std::cout << "\n:::::: destroy random heap zombie event ::::::"<< std::endl;
	delete randomZombie;
	delete randomZombie1;
	delete randomZombie2;
	delete randomZombie3;
	std::cout  << "\n:::::: destroy new heap zombie event ::::::"<< std::endl;
	delete petrZombie;
	std::cout  << "\n:::::: destroy stack event and Zombie inst ::::::"<< std::endl;
	return (0);
}