
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat a;
	a.increment();
	a.increment();
	a.decrement();
	std::cout << " getName : "  << a.getName() << " |  getGrade : " << a.getGrade() << std::endl;
	std::cout << " overload << : " << a << std::endl;
	Bureaucrat aa;
	aa = a;
	std::cout << " overload = : "<< aa << std::endl;
	std::cout << "\n- - - - - - - - - - - \n" << std::endl;
	Bureaucrat b;
	try {
		
		b.decrement();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n- - - - - - - - - - - \n" << std::endl;
	try {
		
		Bureaucrat c(0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
