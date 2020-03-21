
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form("PresidentialPardonForm", 25, 5)
{
	_target = "notarget";
	// std::cout << getName() << ", New PresidentialPardonForm." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm
	(std::string target) :
	Form("PresidentialPardonForm", 25, 5)
{
	_target = target;
	// std::cout << getName() << ", New PresidentialPardonForm." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm
	(const PresidentialPardonForm & obj) :
	Form("PresidentialPardonForm", 25, 5)
{
	// std::cout << getName() << ", New PresidentialPardonForm." << std::endl;
	*this = obj;
}

PresidentialPardonForm &
	PresidentialPardonForm::operator =
			(PresidentialPardonForm const & obj)
{
	_signed = obj.isSigned();
	_target = obj.getTarget();
	return (*this);
}

std::string
	PresidentialPardonForm::getTarget() const
{
	return (_target);
}


void
	PresidentialPardonForm::action() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << getName() << ", PresidentialPardonForm is destroyed." << std::endl;
}

std::ostream &
	operator <<
		(std::ostream & o, PresidentialPardonForm const & obj)
{
	o << obj.getName() << ", PresidentialPardonForm requires :\n" ;
	o << "\ta grade " << obj.getGradeToSign() << " to be signed and \n";
	o << "\tgrade " << obj.getGradeToExecution() <<" to be executed ;\n";
	o << "\tSTATUS : ";
	if (obj.isSigned())
		o << "signed." << std::endl;
	else
		o << "not signed." << std::endl;
	return (o);;
}