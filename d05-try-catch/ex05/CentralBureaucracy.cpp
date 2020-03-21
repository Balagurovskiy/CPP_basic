#include "CentralBureaucracy.hpp"

std::string CentralBureaucracy::_exception = "";

CentralBureaucracy::CentralBureaucracy()
{
	_aviable_blocks = 0;

	srand(time(0));
	int size = _officeBlock_size;
	int i = 0;

	while (i < size){
		Intern intern;
		_officeBlock[i].setIntern(intern);
		i++;
	}
}

CentralBureaucracy::CentralBureaucracy
	(CentralBureaucracy &obj)
{
	*this = obj;
}
CentralBureaucracy & 
	CentralBureaucracy::operator=
		(CentralBureaucracy & obj)
{
	int i = 0;

	while (i < _target_size){
		_target[i] = "";
		i++;
	}
	i = 0;
	while (i < _target_size){
		if (obj._target[i] != ""){
			_target[i] = obj._target[i];
			
		}
		else
			break ;
		i++;
	}
	i = 0;
	while (i < _officeBlock_size){
		if (_officeBlock[i].getSigner() != NULL){
			delete _officeBlock[i].getSigner();
		}
		else if (_officeBlock[i].getExecutor() == NULL){
			delete _officeBlock[i].getExecutor();
		}
		i++;
	}
	i = 0;
	while (i < _officeBlock_size){
		if (obj._officeBlock[i].getSigner() != NULL){
			_officeBlock[i].setSigner(*obj._officeBlock[i].getSigner());
		}
		if (obj._officeBlock[i].getExecutor() == NULL){
			_officeBlock[i].setExecutor(*obj._officeBlock[i].getExecutor());
		}
		i++;
	}
	_aviable_blocks = obj._aviable_blocks;
	return (*this);
}
CentralBureaucracy::~CentralBureaucracy()
{

}
//--------------------------------------
void	CentralBureaucracy::feed(Bureaucrat &obj)
{
	(void) obj;
	int i = 0;

	while (i < _officeBlock_size){
		if (_officeBlock[i].getSigner() == NULL){
			_officeBlock[i].setSigner(obj);
			return ;
		}
		else if (_officeBlock[i].getExecutor() == NULL){
			_officeBlock[i].setExecutor(obj);
			_aviable_blocks++;
			return ;
		}
		i++;
	}
	_exception = FULLOFFICEBLOCKS_EXCPT;
	throw CentralBureaucracyException();
}

void	CentralBureaucracy::queueUp(std::string target)
{
	int i = 0;

	while (i < _target_size){
		if (_target[i] == ""){
			_target[i] = target;
			return ;
		}
		i++;
	}
	_exception = FULLQUEUE_EXCPT;
	throw CentralBureaucracyException();
}
void	CentralBureaucracy::doBureaucracy(void)
{
	int i = 0;
	std::string forms[] =
	{
		"president",
		"robotomy",
		"shrubbery"
	};

	while (_target[i] != ""){
		try
		{
			_officeBlock[rand() % _aviable_blocks].doBureaucracy(forms[rand() % 3], _target[i]);
			std::cout << " - - - ONE MORE FORM IS DONE - - - " << std::endl;
		}
		catch (OfficeBlock::OfficeBlockException & e)
		{
			std::cout << e.what() << e.getErrorMassege() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		i++;
	}
}
//-------------------EXCEPTIONS
CentralBureaucracy::CentralBureaucracyException::CentralBureaucracyException()
{
}
CentralBureaucracy::CentralBureaucracyException::CentralBureaucracyException
		(const CentralBureaucracy::CentralBureaucracyException & obj)
{
	*this = obj;
}
CentralBureaucracy::CentralBureaucracyException &
	CentralBureaucracy::CentralBureaucracyException::operator =
			(CentralBureaucracy::CentralBureaucracyException const & obj)
{
	(void)obj;
	return (*this);
}
const char *
	CentralBureaucracy::CentralBureaucracyException::what() const throw()
{
	return ("EXCEPTION :: CentralBureaucracy ::");
}
std::string
	CentralBureaucracy::CentralBureaucracyException::getErrorMassege()
{
	return (_exception);
}
CentralBureaucracy::CentralBureaucracyException::~CentralBureaucracyException() throw()
{}