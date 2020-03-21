
#include "Logger.hpp"

void		Logger::logToConsole(std::string const & message){
	std::cout << this->makeLogEntry(message) << std::endl;
}
void		Logger::logToFile(std::string const & message){
	std::time_t time = std::time(nullptr);
	std::stringstream timeStream;
	timeStream << std::put_time(std::localtime(&time), "file_%d_%m_%y.logger");
	//std::ios::app - append to the end of file
	std::ofstream outStream(timeStream.str(), std::ios::app);
	if (!outStream)
	{
		std::cout << "Exception: cant create Logger file" << std::endl;
		return;
	}
	outStream << this->makeLogEntry(message) << std::endl;
}

std::string	Logger::makeLogEntry(std::string const & message){
	std::time_t time = std::time(nullptr);
	std::stringstream timeStream;
	timeStream << std::put_time(std::localtime(&time), "\n[date: %d:%m:%y  time: %OH:%OM]\t");
	return (timeStream.str() + message);
}

void		Logger::log(std::string const & dest, std::string const & message){
	std::string actionNames[] = {"Console", "File"};
	
	void (Logger::*actions[])(std::string const & target) = {
		&Logger::logToConsole, 
		&Logger::logToFile
	};

	int i = 3;
	while (--i >= 0)
		if (dest.compare(actionNames[i]) == 0)
			(this->*actions[i])(message);
}