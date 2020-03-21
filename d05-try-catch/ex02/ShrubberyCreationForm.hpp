
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
	private:

		std::string			_target;

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm & obj);

		ShrubberyCreationForm &	operator = (ShrubberyCreationForm const & obj);

		std::string		getTarget() const;

		virtual void	action() const;

		~ShrubberyCreationForm();
};

std::ostream &	operator << (std::ostream & o, ShrubberyCreationForm const & obj);

#endif
