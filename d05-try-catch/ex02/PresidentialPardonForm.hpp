
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
	private:

		std::string			_target;

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm & obj);

		PresidentialPardonForm &	operator = (PresidentialPardonForm const & obj);

		std::string		getTarget() const;

		virtual void	action() const;

		~PresidentialPardonForm();
};

std::ostream &	operator << (std::ostream & o, PresidentialPardonForm const & obj);

#endif
