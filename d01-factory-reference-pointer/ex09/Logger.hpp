

#ifndef LOGGER_HPP
#define LOGGER_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>


class	Logger
{
private:
	void		logToConsole(std::string const & message);
	void		logToFile(std::string const & message);
	std::string	makeLogEntry(std::string const & message);

public:
	void	log(std::string const & dest, std::string const & message);
};

#endif