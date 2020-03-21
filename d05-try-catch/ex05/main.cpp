
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"


int	main(void)
{
	try
	{
		CentralBureaucracy cb;

		int t_size = 8;
		std::string t[] = {"Bob", "Fob", "Wob", "Kob", "Job", "Rob", "Pob", "Gob"};
		for(int i = 0; i < t_size; i++)
			cb.queueUp(t[i]);

		Bureaucrat trash1 = Bureaucrat("FIRST", 37);
		Bureaucrat trash2 = Bureaucrat("SECOND", 4);
		Bureaucrat trash3 = Bureaucrat("THIRD", 55);
		Bureaucrat trash4 = Bureaucrat("FOURTH", 66);

		cb.feed(trash1);
		cb.feed(trash2);
		cb.feed(trash3);
		cb.feed(trash4);

		cb.doBureaucracy();
	}
		catch (CentralBureaucracy::CentralBureaucracyException & e)
	{
		std::cout << e.what() << e.getErrorMassege() << std::endl;
	}
	catch (OfficeBlock::OfficeBlockException & e)
	{
		std::cout << e.what() << e.getErrorMassege() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
