

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("ShrubberyCreationForm", 145, 137)
{
	_target = "<target>";
	std::cout << getName() << " new." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("ShrubberyCreationForm", 145, 137)
{
	_target = target;
	std::cout << getName() << " new." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & obj) :
	Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << getName() << " new." << std::endl;
	*this = obj;
}

ShrubberyCreationForm &
	ShrubberyCreationForm::operator =
			(ShrubberyCreationForm const & obj)
{
	_signed = obj.isSigned();
	_target = obj.getTarget();
	return (*this);
}

std::string
	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void
	ShrubberyCreationForm::action() const
{
	std::ofstream	fout(_target + "_shrubbery");
	fout << "    ##      " << std::endl;
	fout << "   ##o##    " << std::endl;
	fout << " #####o###  " << std::endl;
	fout << "#o#\\#|#/### " << std::endl;
	fout << " ###\\|/#o#  " << std::endl;
	fout << "    }|{     " << std::endl;
	fout << "    }|{     " << std::endl;
	fout.close();

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << getName() << " destroyed." << std::endl;
}

std::ostream &
	operator <<
		(std::ostream & o, ShrubberyCreationForm const & obj)
{
	o << obj.getName() << ", ShrubberyCreationForm requires :\n" ;
	o << "\ta grade " << obj.getGradeToSign() << " to be signed and \n";
	o << "\tgrade " << obj.getGradeToExecution() <<" to be executed ;\n";
	o << "\tSTATUS : ";
	if (obj.isSigned())
		o << "signed." << std::endl;
	else
		o << "not signed." << std::endl;
	return (o);
}