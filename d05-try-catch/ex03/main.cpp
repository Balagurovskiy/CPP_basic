
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void success_test(){
	std::cout << "\n- - - - - Presidential Pardon Form - - - - - \n" << std::endl;
	try {
		Bureaucrat b("Rakesh", 23);
		Bureaucrat b1("Rajesh", 4);
		Form *form;
		Intern randomIntern;

		form = randomIntern.makeForm("PresiDENT", "target-made-by-intern");
		std::cout <<*form;
		b.signForm(*form);
		std::cout <<*form;
		b1.executeForm(*form);
		delete form;
	}	catch (std::exception & e)	{	std::cout << e.what() << std::endl;	}

	std::cout << "\n- - - - - Robotomy Request Form - - - - - \n" << std::endl;
	try {
		Bureaucrat b("Rakesh", 23);
		Bureaucrat b1("Rajesh", 4);
		Form *form;
		Intern randomIntern;

		form = randomIntern.makeForm("RoboToMY", "target-made-by-intern");
		std::cout <<*form;
		b.signForm(*form);
		std::cout <<*form;
		b.executeForm(*form);
		delete form;
	}	catch (std::exception & e)	{	std::cout << e.what() << std::endl;	}
}

void excpt_test(){
	std::cout << "\n- - - - - LOW GRADE TO EXECUTE - - - - \n" << std::endl;
	try {
		Bureaucrat b("Rakesh", 23);
		Bureaucrat b1("Rajesh", 77);
		Form *form;
		Intern randomIntern;

		form = randomIntern.makeForm("robotomy", "target-made-by-intern");
		std::cout <<*form;
		b.signForm(*form);
		std::cout <<*form;
		b1.executeForm(*form);
		delete form;
	}	catch (std::exception & e)	{	std::cout << e.what() << std::endl;	}

	std::cout << "\n- - - - - WRONG FORM TYPE - - - - \n" << std::endl;
	try {
		Form *form;
		Intern randomIntern;

		form = randomIntern.makeForm("hamburger", "target-made-by-intern");
		std::cout <<*form;
		delete form;
	}	catch (std::exception & e)	{	std::cout << e.what() << std::endl;	}
}

int	main(void)
{
	success_test();
	excpt_test();
	return 0;
}
