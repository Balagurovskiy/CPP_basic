
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("Butt")
{
	_grade = 150;
	std::cout <<  "Constructing ... " << *this << std::endl;
}

Bureaucrat::Bureaucrat
	(std::string const name, int const grade) :
		_name(name),
		_grade(grade)
{
	if (_isOverMinGrade())
		throw GradeTooLowException();
	if (_isOverMaxGrade())
		throw GradeTooHighException();
	std::cout <<  "Constructing ... " << *this << std::endl;
}
Bureaucrat::Bureaucrat
	(const Bureaucrat & obj) : _name("Butt")
{
	*this = obj;
}

Bureaucrat &
	Bureaucrat::operator =
		(Bureaucrat const & obj)
{
	_grade = obj.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout <<  "Destructing ... " << *this << std::endl;
}
//---------------------------------------GET / ..
std::string
	Bureaucrat::getName() const
{
	return (_name);
}
int
	Bureaucrat::getGrade() const
{
	return (_grade);
}
//---------------------------------------GRADE SETTERS
void
	Bureaucrat::decrement(void)
{
	std::cout <<  "Decrement ... " << *this << " -> " << _grade + 1 << std::endl;
	_grade++;
	if (_isOverMinGrade())
		throw GradeTooLowException();
}
void
	Bureaucrat::increment(void)
{
	std::cout <<  "Increment ... " << *this << " -> " << _grade - 1 << std::endl;;
	_grade--;
	if (_isOverMaxGrade())
		throw GradeTooHighException();
}
//---------------------------------------GRADE CHECK
bool
	Bureaucrat::_isOverMaxGrade(void) const
{
	return (_grade < _max_grade);
}
bool
	Bureaucrat::_isOverMinGrade(void) const
{
	return (_grade > _min_grade);
}
//---------------------------------------FORM
void
	Bureaucrat::signForm
		(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " cannot sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}
//---------------------------------------CUSTUM EXCEPTIONS
//---------------------------------------CUSTUM EXCEPTIONS - TOO LOW
Bureaucrat::GradeTooLowException::GradeTooLowException()
{}
Bureaucrat::GradeTooLowException::GradeTooLowException
	(const Bureaucrat::GradeTooLowException & obj)
{
	*this = obj;
}
Bureaucrat::GradeTooLowException &
	Bureaucrat::GradeTooLowException::operator =
			(Bureaucrat::GradeTooLowException const & obj)
{
	(void) obj;
	return (*this);
}
const char *
	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("EXCEPTION :: Bureaucrat :: Grade Too Low Exception ::");
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{}
//---------------------------------------CUSTUM EXCEPTIONS - TOO HIGH
Bureaucrat::GradeTooHighException::GradeTooHighException()
{}
Bureaucrat::GradeTooHighException::GradeTooHighException
		(const Bureaucrat::GradeTooHighException & obj)
{
	*this = obj;
}
Bureaucrat::GradeTooHighException &
Bureaucrat::GradeTooHighException::operator =
		(Bureaucrat::GradeTooHighException const & obj)
{
	(void) obj;
	return (*this);
}
const char *
	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("EXCEPTION :: Bureaucrat :: Grade Too High Exception ::");
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{}
//---------------------------------------STREAM OVERLOAD
std::ostream &
	operator <<
		(std::ostream & o, Bureaucrat const & obj)
{
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (o);
}