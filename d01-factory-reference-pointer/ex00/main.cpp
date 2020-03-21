
#include "Pony.hpp"

void	ponyOnTheHeap(){
	Pony	*p = new Pony ("Allah", false);
	delete p;
}

void	ponyOnTheStack(){
	Pony	p = Pony("Den4ik", true);
}

int	main(void){
ponyOnTheHeap();
ponyOnTheStack();
return (0);
}