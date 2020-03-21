
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:

		std::string const	_name;
		int					_grade;


		static int const	_max_grade = 1;
		static int const	_min_grade = 150;

		bool 		_isOverMaxGrade() const;
		bool 		_isOverMinGrade() const;

	public:
		Bureaucrat();
		Bureaucrat(std::string const name, const int grade);
		Bureaucrat(const Bureaucrat & obj);

		Bureaucrat &	operator = (Bureaucrat const & obj);

		std::string		getName() const;
		int				getGrade() const;

		void			decrement();
		void			increment();

		void			signForm(Form& form);

		~Bureaucrat();

		//EXCEPTIONS
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

std::ostream &	operator << (std::ostream & o, Bureaucrat const & obj);

#endif
