//
// Created by Olexiy BALAGUROVSKIY on 2019-07-06.
//

# include "RamModule.hpp"


RamModule::RamModule(){
	this->_data_int_parsed = 0;
}

RamModule::RamModule(RamModule const & src){
	*this = src;
}

RamModule	&
RamModule::operator = (RamModule const & src){
	this->_data_parsed.clear();
	this->_data_int_parsed = src._data_int_parsed;
	for (int i = 0; i < src._data_parsed.size(); ++i) {
		this->_data_parsed.push_back(src._data_parsed.at(i));
	}
	return (*this);
}

RamModule::~RamModule(void){
}

void
RamModule::setData(std::string const & data){
	if (data.empty())
		return ;
	this->_data_parsed.clear();
//------------------OS INFO
	char		buffer[32];
	std::string	out;
	FILE		*stream;
	stream = popen("/usr/bin/sw_vers", "r");
	if (stream)
	{
		while (!feof(stream))
            if (fgets(buffer, 32, stream) != NULL) out.append(buffer);
        pclose(stream);
    }
//------------------RAM

	this->_data_parsed.push_back("RAM\t\t\t\t\t\tOS Info : " + out.substr(13, 8) + " | " + out.substr(38, 7) + " | " + out.substr(60, 5));
	std::string physMem = data.substr(data.find("PhysMem:") + 9, 10);
	physMem = physMem.substr(0, physMem.find("M") + 1);
	this->_data_parsed.push_back("\t\t\t\t\t\tUsed: " + physMem);

	int mem1 = std::atoi(physMem.c_str());

	std::string physMemUnused = data.substr(data.find(" wired),") + 9, 10);
	physMemUnused = physMemUnused.substr(0, physMemUnused.find("M") + 1);
	this->_data_parsed.push_back("\t\t\t\t\t\tUnused: " + physMemUnused);

	int mem2 = std::atoi(physMemUnused.c_str());

	this->_data_int_parsed =  mem1 / ((mem1 + mem2) / 100) ;


}

std::vector<std::string>
RamModule::getData(void) const{
	return (_data_parsed);
}

int
RamModule::getIntData(void) const{
	return (_data_int_parsed);
}