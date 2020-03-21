
#include "OfficeBlock.hpp"

std::string OfficeBlock::_exception = "";

OfficeBlock::OfficeBlock() :
	_signer(NULL),
	_executor(NULL),
	_intern(NULL)
{
	std::cout << "OfficeBlock is open." << std::endl;
}
OfficeBlock::OfficeBlock
		(Bureaucrat *signer, Bureaucrat *executor, Intern *intern):
	_signer(signer),
	_executor(executor),
	_intern(intern)
{
	std::cout << "OfficeBlock is open." << std::endl;
}
OfficeBlock::~OfficeBlock()
{
	std::cout << "OfficeBlock is closed." << std::endl;
}


void
	OfficeBlock::setIntern
			(Intern &intern)
{
	this->_intern = &intern;
}
void
	OfficeBlock::setSigner
			(Bureaucrat &signer)
{
	this->_signer = &signer;
}
void
	OfficeBlock::setExecutor
			(Bureaucrat &executor)
{
	this->_executor = &executor;
}
void
	OfficeBlock::doBureaucracy
		(std::string const type, std::string const target)
{
	if (_executor == NULL)
	{
		_exception = NO_EXECUTOR_EXCPT;
		throw OfficeBlock::OfficeBlockException();
	}
	if (_signer == NULL)
	{
		_exception = NO_SIGNER_EXCPT;
		throw OfficeBlock::OfficeBlockException();
	}
	if (_intern == NULL)
	{
		_exception = NO_INTERN_EXCPT;
		throw OfficeBlock::OfficeBlockException();
	}

	Form *form = _intern->makeForm(type, target);
	_signer->signForm(*form);
	_executor->executeForm(*form);
	if (form)
		delete form;
}


OfficeBlock::OfficeBlockException::OfficeBlockException()
{
}
OfficeBlock::OfficeBlockException::OfficeBlockException
		(const OfficeBlockException & obj)
{
	*this = obj;
}
OfficeBlock::OfficeBlockException &
OfficeBlock::OfficeBlockException::operator =
		(OfficeBlock::OfficeBlockException const & obj)
{
	(void)obj;
	return (*this);
}
const char *
OfficeBlock::OfficeBlockException::what() const throw()
{
	return ("EXCEPTION :: OfficeBlock ::");
}
std::string
	OfficeBlock::OfficeBlockException::getErrorMassege()
{
	return (_exception);
}
OfficeBlock::OfficeBlockException::~OfficeBlockException() throw()
{}
