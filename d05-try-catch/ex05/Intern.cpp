
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



Intern::Intern()
{
	// std::cout <<"Intern was hired." << std::endl;
}

Intern::Intern
		(const Intern & obj)
{
	*this = obj;
	// std::cout <<"Intern was hired." << std::endl;
}

Intern &
Intern::operator =
		(Intern const & obj)
{
	(void)obj;
	return (*this);
}

Intern::~Intern()
{
	// std::cout << "Intern was fired." << std::endl;
}

Form *
Intern::makeForm
		(std::string const type, std::string const target) const
{
	std::string typeLower;
	int i = -1;
	int size = type.size();

	while(++i < size)
		typeLower += std::tolower(type[i]);
	if (typeLower.compare("shrubbery") == 0)
		return (new ShrubberyCreationForm(target));
	if (typeLower.compare("robotomy") == 0)
		return (new RobotomyRequestForm(target));
	if (typeLower.compare("president") == 0)
		return (new PresidentialPardonForm(target));
	throw Intern::WrongForm();
	return (NULL);
}

//-------------------------------------------------------------------
std::ostream &	operator << (std::ostream & o, Intern const & obj)
{
	(void)obj;
	o << "Intern" << std::endl;
	return (o);;
}
//-------------------------------------------------------------------
Intern::WrongForm::WrongForm()
{
}

Intern::WrongForm::WrongForm
		(const WrongForm & obj)
{
	*this = obj;
}

Intern::WrongForm &
Intern::WrongForm::operator =
		(Intern::WrongForm const & obj)
{
	(void)obj;
	return (*this);
}

const char *
Intern::WrongForm::what() const throw()
{
	return ("EXCEPTION :: Intern :: There is no form with this type ::");
}

Intern::WrongForm::~WrongForm() throw()
{
}