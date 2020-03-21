
#include "Pony.hpp"

Pony::Pony(std::string n, bool a) : name(n), ability(a)
{
	std::cout << "\nHello Pony " << this->name << std::endl;
	if (ability)
		std::cout << "\t" << this->name << " has a special ability and became a STRAPONY" << std::endl;
	return;
}

Pony::~Pony(void) 
{
	std::cout << "Goodbye Pony " << this->name << std::endl;
	return;
}