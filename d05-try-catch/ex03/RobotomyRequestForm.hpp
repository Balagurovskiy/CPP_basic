

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
	private:

		std::string			_target;

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm & obj);

		RobotomyRequestForm &	operator = (RobotomyRequestForm const & obj);

		std::string		getTarget() const;

		virtual void	action() const;

		~RobotomyRequestForm();
};

std::ostream &	operator << (std::ostream & o, RobotomyRequestForm const & obj);

#endif
