
#ifndef CENTRALBUEAUCRACY_HPP
#define CENTRALBUEAUCRACY_HPP

#include "OfficeBlock.hpp"

// # define NO_SIGNER_EXCPT " Signer wasnt setted !"
// # define NO_EXECUTOR_EXCPT " Executor wasnt setted !"
# define FULLOFFICEBLOCKS_EXCPT " Office blocks are full !"
# define FULLQUEUE_EXCPT " Queue is full !"

class CentralBureaucracy {
	private:

		static int const _officeBlock_size = 20;
		static int const _target_size = 30;

		OfficeBlock		_officeBlock[_officeBlock_size];
		std::string		_target[_target_size];

		int 			_aviable_blocks;
		static std::string _exception;
	public:
		CentralBureaucracy();
		CentralBureaucracy(CentralBureaucracy &obj);
		CentralBureaucracy &operator=(CentralBureaucracy &r);
		~CentralBureaucracy();


		void	feed(Bureaucrat &obj);
		void	queueUp(std::string obj);
		void	doBureaucracy(void);

		class CentralBureaucracyException
		{
			public:
				CentralBureaucracyException();
				CentralBureaucracyException(const CentralBureaucracyException & obj);
				CentralBureaucracyException &	operator = (CentralBureaucracyException const & obj);
				virtual const char*	what() const throw();
				std::string getErrorMassege();
				~CentralBureaucracyException() throw();
		};
};


#endif 