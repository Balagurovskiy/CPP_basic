
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

void invalid_form_type_test(){
	std::cout << "\n- - - - - INVALID FORM TYPE - - - - \n" << std::endl;
	Intern garbage;
	Bureaucrat trash1 = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat trash2 = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;
	ob.setIntern(garbage);
	ob.setSigner(trash2);
	ob.setExecutor(trash1);
	try
	{
		ob.doBureaucracy("mutant pig termination", "Pigley");
	}
	catch (OfficeBlock::OfficeBlockException & e)
	{
		std::cout << e.what() << e.getErrorMassege() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
void low_grade_exception_test(){
	std::cout << "\n- - - - - LOW GRADE EXCEPTION - - - - \n" << std::endl;
	Intern garbage;
	Bureaucrat trash1 = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat trash2 = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;
	ob.setIntern(garbage);
	ob.setSigner(trash2);
	ob.setExecutor(trash1);
	try
	{
		ob.doBureaucracy("robotomy", "Pigley");
	}
	catch (OfficeBlock::OfficeBlockException & e)
	{
		std::cout << e.what() << e.getErrorMassege() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
void no_intern_test(){
	std::cout << "\n- - - - - NO INTERN EXCEPTION - - - - \n" << std::endl;
	Bureaucrat trash1 = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat trash2 = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;
	ob.setSigner(trash2);
	ob.setExecutor(trash1);
	try
	{
		ob.doBureaucracy("robotomy", "Pigley");
	}
	catch (OfficeBlock::OfficeBlockException & e)
	{
		std::cout << e.what() << e.getErrorMassege() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
void no_ex_test(){
	std::cout << "\n- - - - - NO EXECUTOR EXCEPTION - - - - \n" << std::endl;
	Intern garbage;
	Bureaucrat trash2 = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;
	ob.setIntern(garbage);
	ob.setSigner(trash2);
	try
	{
		ob.doBureaucracy("robotomy", "Pigley");
	}
	catch (OfficeBlock::OfficeBlockException & e)
	{
		std::cout << e.what() << e.getErrorMassege() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
void no_signer_test(){
	std::cout << "\n- - - - - NO SIGNER EXCEPTION - - - - \n" << std::endl;
	Intern garbage;
	Bureaucrat trash1 = Bureaucrat("Hermes Conrad", 37);
	OfficeBlock ob;
	ob.setIntern(garbage);
	ob.setExecutor(trash1);
	try
	{
		ob.doBureaucracy("robotomy", "Pigley");
	}
	catch (OfficeBlock::OfficeBlockException & e)
	{
		std::cout << e.what() << e.getErrorMassege() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
void success_test(){
	std::cout << "\n- - - - - SUCCESS EXCEPTION - - - - \n" << std::endl;
	Intern garbage;
	Bureaucrat trash1 = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat trash2 = Bureaucrat("Bobby Bobson", 66);
	OfficeBlock ob;
	ob.setIntern(garbage);
	ob.setSigner(trash2);
	ob.setExecutor(trash1);
	try
	{
		ob.doBureaucracy("robotomy", "Pigley");
	}
	catch (OfficeBlock::OfficeBlockException & e)
	{
		std::cout << e.what() << e.getErrorMassege() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
int	main(void)
{
	success_test();
	invalid_form_type_test();
	low_grade_exception_test();
	no_intern_test();
	no_ex_test();
	no_signer_test();

	return 0;
}
