#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"
void more_tests(Character* zaz, AWeapon* pr, AWeapon* pf){

	std::cout << std::endl;

	std::cout << *zaz;

	std::cout << std::endl;
	std::cout << "\n" << zaz->getName() <<" * is recovering AP * \n"<< std::endl;
	zaz->equip(NULL);
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;

	std::cout << std::endl;

	Enemy* c = new SuperMutant();

	std::cout << std::endl;

	zaz->equip(pf);
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;

	std::cout << "\n * attack without AP * "<< std::endl;
	std::cout << c->getType() << "  hp: "<< c->getHP() << "\n" << std::endl;
	
	zaz->attack(c);
	std::cout << *zaz;

	std::cout << std::endl;

	zaz->recoverAP();
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;
}
int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;

	// more_tests(zaz, pr, pf);
	return 0;
}