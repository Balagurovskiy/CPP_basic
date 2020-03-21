
#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include "Bureaucrat.hpp"
#include "Intern.hpp"

# define NO_SIGNER_EXCPT " Signer wasnt setted !"
# define NO_EXECUTOR_EXCPT " Executor wasnt setted !"
# define NO_INTERN_EXCPT " Intern wasnt setted !"

class OfficeBlock {
	private:
		Bureaucrat * 	_signer;
		Bureaucrat * 	_executor;
		Intern * 		_intern;

		static std::string _exception;
	public:
		OfficeBlock();
		OfficeBlock(Bureaucrat *signer, Bureaucrat *executor, Intern *intern);
		~OfficeBlock();

		void	setIntern(Intern &intern);
		void	setSigner(Bureaucrat &signer);
		void	setExecutor(Bureaucrat &executor);
		Intern		*getIntern(void);
		Bureaucrat	*getSigner(void);
		Bureaucrat	*getExecutor(void);
		void	doBureaucracy(std::string const type, std::string const target);

		class OfficeBlockException
		{
			public:
				OfficeBlockException();
				OfficeBlockException(const OfficeBlockException & obj);
				OfficeBlockException &	operator = (OfficeBlockException const & obj);
				virtual const char*	what() const throw();
				std::string getErrorMassege();
				~OfficeBlockException() throw();
		};
};


#endif //DAY05_OFFICEBLOCK_HPP
