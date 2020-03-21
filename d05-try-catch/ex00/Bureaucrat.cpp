
#include "Bureaucrat.hpp"

std::string Bureaucrat::_exception = "";

Bureaucrat::Bureaucrat(void) : _name("Butt")
{
	_grade = 150;
	std::cout <<  "Constructing ... " << *this << std::endl;
}

Bureaucrat::Bureaucrat
	(int const grade) : _name("Butt")
{
	this->_grade = grade;
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
	if (_grade < _max_grade){
		_exception += "Grade (";
		_exception += std::to_string(_grade) + ") is higher then maximum (";
		_exception += std::to_string(_max_grade) + ") !\n";
		return (true);
	}
	return (false);
}
bool
	Bureaucrat::_isOverMinGrade(void) const
{
	if (_grade > _min_grade){
		_exception += "Grade (";
		_exception += std::to_string(_grade) + ") is lower then minimum (";
		_exception += std::to_string(_min_grade) + ") !\n";
		return (true);
	}
	return (false);
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
	std::string excptnMssg = "\nEXCEPTION :: Bureaucrat :: Grade Too Low Exception :: ";
	excptnMssg += "\n\t\t";
	excptnMssg += Bureaucrat::_exception;
	std::cout << excptnMssg << std::endl;
	return ("What? Too Low ?");
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
	std::string excptnMssg = "\nEXCEPTION :: Bureaucrat :: Grade Too High Exception :: ";
	excptnMssg += "\n\t\t";
	excptnMssg += Bureaucrat::_exception;
	std::cout << excptnMssg << std::endl;
	return ("What? Too High ?");
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