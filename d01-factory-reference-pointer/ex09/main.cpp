

#include "Logger.hpp"

int		main(void)
{
	Logger logger;

	logger.log("Console", "This log was pushed to console");
	logger.log("File", "This random lines were \n pushed to logger file");
}