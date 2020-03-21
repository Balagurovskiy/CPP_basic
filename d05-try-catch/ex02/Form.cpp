/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:08:41 by igaliuk           #+#    #+#             */
/*   Updated: 2019/07/03 16:01:56 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() :
	_name("F_o_r_m"),
	_gradeToSign(50),
	_gradeToExecute(100)
{
	_signed = false;
	std::cout << getName() << ", form created." << std::endl;
}

Form::Form
	(std::string name, int gradeSign, int gradeExe) :
	_name(name),
	_signed(false),
	_gradeToSign(gradeSign),
	_gradeToExecute(gradeExe)
{
	if (_isOverMinGrade())
		throw GradeTooLowException();
	if (_isOverMaxGrade())
		throw GradeTooHighException();
	std::cout << getName() << ", form created." << std::endl;
}

Form::Form
	(const Form & obj) :
	_name(obj.getName()),
	_signed(false),
	_gradeToSign(obj.getGradeToSign()),
	_gradeToExecute(obj.getGradeToExecution())
{
	std::cout << getName() << ", form created." << std::endl;
	*this = obj;
}

Form::~Form()
{
	std::cout << getName() << ", Form is shredered." << std::endl;
}

Form &	Form::operator = (Form const & obj)
{
	(void) obj;
	return (*this);
}


//---------------------------------------GET
std::string
	Form::getName() const
{
	return (_name);
}

bool
	Form::isSigned() const
{
	return (_signed);
}

int
	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int
	Form::getGradeToExecution() const
{
	return (_gradeToExecute);
}


//---------------------------------------BUREAUCRAT SIGN CHECK
void
	Form::beSigned
		(Bureaucrat const & obj)
{
	if (_gradeToSign < obj.getGrade())
		throw	Form::GradeTooLowException();
	_signed = true;
}
void
	Form::execute
		(Bureaucrat const & obj) const
{
	if (_signed)
	{
		if (_gradeToExecute > obj.getGrade())
		{
			this->action();
		}
		else
			throw GradeTooLowException();
	}
	else
		throw ExecuteException();
}
//---------------------------------------GRADE CHECK
bool
	Form::_isOverMaxGrade(void) const
{
	return (_gradeToExecute < _max_grade || _gradeToSign < _max_grade);
}
bool
	Form::_isOverMinGrade(void) const
{
	return (_gradeToExecute > _min_grade || _gradeToSign > _min_grade);
}

//---------------------------------------CUSTUM EXCEPTIONS
//---------------------------------------CUSTUM EXCEPTIONS - TOO LOW
Form::GradeTooLowException::GradeTooLowException()
{
}
Form::GradeTooLowException::GradeTooLowException
	(const GradeTooLowException & obj)
{
	*this = obj;
}
Form::GradeTooLowException &
	Form::GradeTooLowException::operator =
			(Form::GradeTooLowException const & obj)
{
	(void)obj;
	return (*this);
}
const char *
	Form::GradeTooLowException::what() const throw()
{
	return ("EXCEPTION :: Form :: Grade Too Low Exception ::");
}
Form::GradeTooLowException::~GradeTooLowException() throw()
{}
//---------------------------------------CUSTUM EXCEPTIONS - TOO HIGH
Form::GradeTooHighException::GradeTooHighException()
{}
Form::GradeTooHighException::GradeTooHighException
	(const GradeTooHighException & obj)
{
	*this = obj;
}
Form::GradeTooHighException &
	Form::GradeTooHighException::operator =
			(Form::GradeTooHighException const & obj)
{
	(void)obj;
	return (*this);
}
const char *
	Form::GradeTooHighException::what() const throw()
{
	return ("EXCEPTION :: Form :: Grade Too High Exception ::");
}
Form::GradeTooHighException::~GradeTooHighException() throw()
{}
//---------------------------------------CUSTUM EXCEPTIONS - Signed
Form::SignedException::SignedException()
{}
Form::SignedException::SignedException
		(const SignedException & obj)
{
	*this = obj;
}
Form::SignedException &
	Form::SignedException::operator =
		(Form::SignedException const & obj)
{
	(void)obj;
	return (*this);
}
const char *
Form::SignedException::what() const throw()
{
	return ("EXCEPTION :: Form :: Already Signed Exception ::");
}
Form::SignedException::~SignedException() throw()
{}
//---------------------------------------CUSTUM EXCEPTIONS - Execution
Form::ExecuteException::ExecuteException()
{}
Form::ExecuteException::ExecuteException
		(const ExecuteException & obj)
{
	*this = obj;
}
Form::ExecuteException &
	Form::ExecuteException::operator =
		(Form::ExecuteException const & obj)
{
	(void)obj;
	return (*this);
}
const char *
Form::ExecuteException::what() const throw()
{
	return ("EXCEPTION :: Form :: Execute Exception (Not Signed)::");
}
Form::ExecuteException::~ExecuteException() throw()
{}
//---------------------------------------STREAM OVERLOAD
std::ostream &	operator << (std::ostream & o, Form const & obj)
{
	o << obj.getName() << ", form requires :\n" ;
	o << "\ta grade " << obj.getGradeToSign() << " to be signed and \n";
	o << "\tgrade " << obj.getGradeToExecution() <<" to be executed ;\n";
	o << "\tSTATUS : ";
	if (obj.isSigned())
		o << "signed." << std::endl;
	else
		o << "not signed." << std::endl;
	return (o);;
}