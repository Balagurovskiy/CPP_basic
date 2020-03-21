
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void success_test(){
	std::cout << "\n- - - - - Shrubbery Creation Form - - - - - \n" << std::endl;
	try {
		Bureaucrat b("Rakesh", 3);
		Form *f = new ShrubberyCreationForm("Shrubb-23-A#2");//s145, e137
		std::cout <<*f;
		b.signForm(*f);
		std::cout <<*f;
		b.executeForm(*f);
		delete f;
	}
	catch (std::exception & e)	{	std::cout << e.what() << std::endl;	}
	std::cout << "\n- - - - - Presidential Pardon Form - - - - - \n" << std::endl;
	try {
		Bureaucrat b("Rakesh", 3);
		Form *f = new PresidentialPardonForm("President-00-D#2");//s25, e5
		std::cout <<*f;
		b.signForm(*f);
		std::cout <<*f;
		b.executeForm(*f);
		delete f;
	}
	catch (std::exception & e)	{	std::cout << e.what() << std::endl;	}

	std::cout << "\n- - - - - Robotomy Request Form - - - - - \n" << std::endl;
	try {
		Bureaucrat b("Rakesh", 3);
		Form *f = new RobotomyRequestForm("Robot-01-10");//s75, e45
		std::cout <<*f;
		b.signForm(*f);
		std::cout <<*f;
		b.executeForm(*f);
		b.executeForm(*f);
		b.executeForm(*f);
		delete f;
	}
	catch (std::exception & e)	{	std::cout << e.what() << std::endl;	}
}

void low_grade_test(){
	std::cout << "\n- - - - - LOW GRADE TO EXECUTE - - - - \n" << std::endl;
	try {
		Bureaucrat b("Rakesh", 6);
		Form *f = new PresidentialPardonForm("President-00-D#2");//s25, e5
		std::cout <<*f;
		b.signForm(*f);
		std::cout <<*f;
		b.executeForm(*f);
		delete f;
	}
	catch (std::exception & e)	{	std::cout << e.what() << std::endl;	}

	std::cout << "\n- - - - - LOW GRADE TO SIGN AND EXECUTE - - - - \n" << std::endl;
	try {
		Bureaucrat b("Rakesh", 76);
		Form *f = new RobotomyRequestForm("Robot-01-10");//s75, e45
		std::cout <<*f;
		b.signForm(*f);
		std::cout <<*f;
		b.executeForm(*f);
		delete f;
	}
	catch (std::exception & e)	{	std::cout << e.what() << std::endl;	}
}

void not_signed_test(){
	std::cout << "\n- - - - - EXECUTION OF NOT SIGNED FORM - - - - \n" << std::endl;
	try {
		Bureaucrat b("Rakesh", 3);
		Form *f = new PresidentialPardonForm("President-00-D#2");//s25, e5
		std::cout <<*f;
		b.executeForm(*f);
		delete f;
	}
	catch (std::exception & e)	{		std::cout << e.what() << std::endl;	}

	std::cout << "\n- - - - - EXECUTION OF FORM SIGNED BY ANOTHER B- - - - \n" << std::endl;
	try {
		Bureaucrat b("Rakesh", 72);
		Bureaucrat b1("Rajesh", 44);
		Form *f = new RobotomyRequestForm("Robot-01-10");//s72, e45
		std::cout <<*f;
		b.signForm(*f);
		std::cout <<*f;
		b1.executeForm(*f);
		delete f;
	}
	catch (std::exception & e)	{	std::cout << e.what() << std::endl;	}
}
int	main(void)
{
	success_test();

	low_grade_test();

	not_signed_test();
	return 0;
}
