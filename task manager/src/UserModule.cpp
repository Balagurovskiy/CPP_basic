//
// Created by Olexiy BALAGUROVSKIY on 2019-07-06.
//

# include "UserModule.hpp"


UserModule::UserModule(){
	this->_data_int_parsed = 0;
}

UserModule::UserModule(UserModule const & src){
	*this = src;
}

UserModule	&
UserModule::operator = (UserModule const & src){
	this->_data_parsed.clear();
	this->_data_int_parsed = src._data_int_parsed;
	for (int i = 0; i < src._data_parsed.size(); ++i) {
		this->_data_parsed.push_back(src._data_parsed.at(i));
	}
	return (*this);
}

UserModule::~UserModule(void){
}

void
UserModule::setData(std::string const & data){
	if (data.empty())
		return ;
	this->_data_parsed.clear();
//-----------------HOSTNAME

	char		buffer[32];
	std::string	out;
	FILE		*stream;

	stream = popen("/bin/hostname", "r");
	if (stream)
	{
		while (!feof(stream))
            if (fgets(buffer, 32, stream) != NULL) out.append(buffer);
        pclose(stream);
    }
//------------------NETWORK
	this->_data_parsed.push_back("Network");
	std::string physMem = data.substr(data.find("Networks: packets:") + 19, 10);
	physMem = physMem.substr(0, physMem.find("/"));
	this->_data_parsed.push_back("\t\t\t\t\t\t IN : " + physMem);

	int packs = std::atoi(physMem.c_str()) / 100000;
	this->_data_int_parsed = ( packs > 100) ? 100 : packs;

	std::string physMemUnused = data.substr(data.find(" in, ") + 5, 10);
	physMemUnused = physMemUnused.substr(0, physMemUnused.find("/"));
	this->_data_parsed.push_back("\t\t\t\t\t\t OUT : " + physMemUnused);

	this->_data_parsed.push_back("*");
	this->_data_parsed.push_back("Date : " + data.substr(data.find("threads") + 7, 21));
	this->_data_parsed.push_back("Hostname : " + out.substr(0, out.size() - 1));

}

std::vector<std::string>
UserModule::getData(void) const{
	return (_data_parsed);
}

int
UserModule::getIntData(void) const{
	return (_data_int_parsed);
}