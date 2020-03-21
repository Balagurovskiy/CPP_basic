
#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Intern
{
	public:

		Intern();
		Intern(const Intern & obj);
		Intern &	operator = (Intern const & obj);

		Form*		makeForm (std::string const type, std::string const target) const;

		~Intern();

		class WrongForm : public std::exception
		{
			public:
				WrongForm();
				WrongForm(const WrongForm & obj);
				WrongForm &	operator = (WrongForm const & obj);
				virtual const char*	what() const throw();
				~WrongForm() throw();
		};
};

std::ostream &	operator << (std::ostream & o, Intern const & obj);

#endif
