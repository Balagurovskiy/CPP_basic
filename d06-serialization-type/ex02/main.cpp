
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base *
	generate(void)
{
	srand(time(0));

	int r = rand() % 3;

	switch (r) {
		case 0: 
			std::cout << "-> A" << std::endl;
			return new A;
		case 1:
			std::cout << "-> B" << std::endl;
			return new B;
		case 2:
			std::cout << "-> C" << std::endl;
			return new C;
		default: 
			return NULL;
	}
}

void
	identify_from_pointer(Base * base)
{
	if (dynamic_cast<A*>(base))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(base))
		std::cout << "C" << std::endl;
}

void
	identify_from_reference(Base & base)
{
	if (dynamic_cast<A*>(&base))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&base))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&base))
		std::cout << "C" << std::endl;
}

int	main()
{

	std::cout << "Generating A, B or C" << std::endl;
	Base	*base = generate();
	std::cout << "identify_from_pointer" << std::endl;
	identify_from_pointer(base);
	std::cout << "identify_from_reference" << std::endl;
	identify_from_reference(*base);
	delete base;
	return (0);
}