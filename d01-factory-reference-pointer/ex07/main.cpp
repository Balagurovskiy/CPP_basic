


#include <iostream>
#include <fstream>

void	printUsage(){
	std::string usageMsg;

	usageMsg = "\n\tUSAGE: ./replace \t\"file name\" \t\"string to replace\" \t\"new string\"";
	std::cout << usageMsg << std::endl;
}

void 	replaceInLine(std::string &line, std::string targetW, std::string newW){
	size_t position;

	position = line.find(targetW);
	//std::string::npos - end of line, if size_t pos == -1 <-> max size_t
	while (position != std::string::npos){
		line.replace(position, targetW.length(), newW);
		position = line.find(targetW, position + newW.length());
	}
}

int		main(int ac, char **av)
{
	if (ac == 4){
		std::string	sourceFile = av[1];
		std::string targetW = av[2];
		std::string	newW = av[3];

		std::ifstream inputStream(sourceFile);
		if (inputStream && !targetW.empty()){
			std::ofstream outStream(sourceFile + ".replace");
			if (outStream){
				std::string	currLine;
				while (std::getline(inputStream, currLine))
				{
					replaceInLine(currLine, targetW, newW);
					outStream << currLine << std::endl;
				}
			}
			else
				printUsage();
		}
		else
			printUsage();
	}
	else
		printUsage();
	return (0);
}