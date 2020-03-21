

#include "Peon.hpp"
#include "Poen.hpp"
#include "Victim.hpp"
#include "Sorcerer.hpp"

int main() 
{
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");
	// Poen sanya("Sanya");

	std::cout << robert << jim << joe << sanya;
	// std::cout << sanya;

	robert.polymorph(jim);
	robert.polymorph(joe);
	// robert.polymorph(sanya);


	return 0;
}