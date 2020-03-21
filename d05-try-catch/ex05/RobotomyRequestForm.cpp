

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	Form("RobotomyRequestForm", 72, 45)
{
	_target = "notarget";
	// std::cout << getName() << " new." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm
	(std::string target) :
	Form("RobotomyRequestForm", 72, 45)
{
	_target = target;
	// std::cout << getName() << " new." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm
	(const RobotomyRequestForm & obj) :
	Form("RobotomyRequestForm", 72, 45)
{
	std::cout << getName() << " new." << std::endl;
	*this = obj;
}

RobotomyRequestForm &
	RobotomyRequestForm::operator =
			(RobotomyRequestForm const & obj)
{
	_signed = obj.isSigned();
	_target = obj.getTarget();
	return (*this);
}

std::string
	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void
	RobotomyRequestForm::action() const
{

	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " has been robotomized failure" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << getName() << "destroyed." << std::endl;
}

std::ostream &
	operator <<
		(std::ostream & o, RobotomyRequestForm const & obj)
{
	o << obj.getName() << ", RobotomyRequestForm requires :\n" ;
	o << "\ta grade " << obj.getGradeToSign() << " to be signed and \n";
	o << "\tgrade " << obj.getGradeToExecution() <<" to be executed ;\n";
	o << "\tSTATUS : ";
	if (obj.isSigned())
		o << "signed." << std::endl;
	else
		o << "not signed." << std::endl;
	return (o);;
}
