
#include "Bureaucrat.hpp"
#include "Form.hpp"
int	main(void)
{
	try {
		Bureaucrat b("Rakesh",3);
		Form f("F-23-A#2", 2, 150);

		std::cout <<f;
		f.beSigned(b);
		std::cout <<f;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n- - - - - - - - - - - \n" << std::endl;
	try {
		Bureaucrat b("Rakesh",2);
		Form f("F-23-A#2", 2, 150);

		std::cout <<f;
		b.decrement();
		b.signForm(f);
		std::cout <<f;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
