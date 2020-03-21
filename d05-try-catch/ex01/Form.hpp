
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;

		static int const	_max_grade = 1;
		static int const	_min_grade = 150;

		bool 				_isOverMaxGrade() const;
		bool 				_isOverMinGrade() const;

	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExe);
		Form(const Form & obj);

		Form &	operator = (Form const & obj);

		std::string		getName() const;
		bool			isSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecution() const;

		void			beSigned(Bureaucrat const & obj);

		~Form();

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				GradeTooLowException(const GradeTooLowException & obj);
				GradeTooLowException &	operator = (GradeTooLowException const & obj);
				virtual const char*	what() const throw();
				~GradeTooLowException() throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();
				GradeTooHighException(const GradeTooHighException & obj);
				GradeTooHighException &	operator = (GradeTooHighException const & obj);
				virtual const char*	what() const throw();
				~GradeTooHighException() throw();
		};


};

std::ostream &	operator << (std::ostream & o, Form const & obj);

#endif
