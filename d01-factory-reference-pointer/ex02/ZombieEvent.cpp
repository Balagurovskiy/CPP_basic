

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void){
	this->_type = "NoType";
	this->_randomEntry = 1;
	return;
}

ZombieEvent::~ZombieEvent(void) 
{
	std::cout << "Zombie Event destroyed" << std::endl;
	return;
}

void	ZombieEvent::setZombieType(std::string type){
	this->_type = type;
}

Zombie	*ZombieEvent::newZombie(std::string name){
	return (new Zombie(name, this->_type));
}

Zombie	*ZombieEvent::randomChump(){
	std::string first[] = {"Georgiy ", "Alexandr ", "Petr ", "Vlad ", "Anna ", "Lydmila "};
	std::string second[] = {"Sergevich ", "Vladimirovich ", "Semenovich ", "Ivanovich ", "Vitalievich ", "Kuzmich "};
	std::string last[] = {"Shmatko", "Lobko", "Chlenko", "Lyshko", "Babko", "Krabko"};
	std::string name;
	int i = 0;
	
	// srand(time(0));
	while (i < this->_randomEntry){
		name = "";
		name += first[std::rand() % 5];
		name += second[std::rand() % 5];
		name += last[std::rand() % 5];
		i++;
	}
	this->_randomEntry = 1 + rand() % 100;
	return (new Zombie(name, this->_type));
}