//
// Created by Olexiy BALAGUROVSKIY on 2019-07-06.
//

# include "CpuModule.hpp"


CpuModule::CpuModule(){
	this->_data_int_parsed = 0;
}

CpuModule::CpuModule(CpuModule const & src){
	*this = src;
}

CpuModule	&
CpuModule::operator = (CpuModule const & src){
	this->_data_parsed.clear();
	this->_data_int_parsed = src._data_int_parsed;
	for (int i = 0; i < src._data_parsed.size(); ++i) {
		this->_data_parsed.push_back(src._data_parsed.at(i));
	}
	return (*this);
}

CpuModule::~CpuModule(void){
}

void
CpuModule::setData(std::string const & data){
	if (data.empty())
		return ;
	this->_data_parsed.clear();

	char		buffer[32];
	std::string	out;
	FILE		*stream;
//------------------ID
	stream = popen("/usr/bin/id -un", "r");
	if (stream)
	{
		while (!feof(stream))
            if (fgets(buffer, 32, stream) != NULL) out.append(buffer);
        pclose(stream);
    }
//------------------CPU
	this->_data_parsed.push_back("CPU\t\t\t\t\t\tID : " + out.substr(0, out.size() - 1));
	std::string physMem = data.substr(data.find("CPU usage:") + 11, 7);
	physMem = physMem.substr(0, physMem.find("%") + 1);
	this->_data_parsed.push_back("\t\t\t\t\t\tUsage: " + physMem);
	this->_data_int_parsed = std::atoi(physMem.c_str());

	std::string physMemUnused = data.substr(data.find("CPU usage:") + 23, 7);
	physMemUnused = physMemUnused.substr(0, physMemUnused.find("%") + 1);
	this->_data_parsed.push_back("\t\t\t\t\t\tUser: " + physMemUnused);
}

std::vector<std::string>
CpuModule::getData(void) const{
	return (_data_parsed);
}

int
CpuModule::getIntData(void) const{
	return (_data_int_parsed);
}