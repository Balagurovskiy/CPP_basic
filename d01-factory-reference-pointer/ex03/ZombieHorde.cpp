
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n){
	this->_horde_amount = n;
	this->_random_entry = 1;
	if (this->_horde_amount < 0)
		this->_horde_amount = 0;
	this->_horde = new Zombie[this->_horde_amount];
	this->initHorde();
	return;
}

ZombieHorde::~ZombieHorde(void){
	delete [] this->_horde;
	return;
}

void		 	ZombieHorde::initHorde(){
	int i = 0;

	while (i < this->_horde_amount){
		this->_horde[i]._name = this->randomName(i);
		this->_horde[i]._type = this->randomName(i);
		i++;
	}
}

void		 	ZombieHorde::announce(){
	int i = 0;

	while (i < this->_horde_amount){
		this->_horde[i].announce();
		i++;
	}
}

std::string		ZombieHorde::randomName(int k){
	std::string n1[] = {"Bo", "Ah", "Ge", "Ra", "Al", "Kla"};
	std::string n2[] = {"ri", "me", "na", "m", "be", "ri"};
	std::string n3[] = {"so", "to", "di", "za", "r", "so"};
	std::string n4[] = {"vich", "v", "y", "nchik", "t", "va"};
	std::string name;	
	int i = 0;
	
	while (i < this->_random_entry){
		name = "";
		name += n1[std::rand() % 5];
		name += n2[std::rand() % 5];
		name += n3[std::rand() % 5];
		name += n4[std::rand() % 5];
		i++;
	}
	this->_random_entry = 1 + rand() % (100 + k * 100);
	return (name);
}