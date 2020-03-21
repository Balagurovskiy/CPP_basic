//
// Created by Olexiy BALAGUROVSKIY on 2019-07-06.
//

# include "BonusModule.hpp"


BonusModule::BonusModule(){
	this->_data_int_parsed = 0;
}

BonusModule::BonusModule(BonusModule const & src){
	*this = src;
}

BonusModule	&
BonusModule::operator = (BonusModule const & src){
	this->_data_parsed.clear();
	this->_data_int_parsed = src._data_int_parsed;
	for (int i = 0; i < src._data_parsed.size(); ++i) {
		this->_data_parsed.push_back(src._data_parsed.at(i));
	}
	return (*this);
}

BonusModule::~BonusModule(void){
}

void
BonusModule::setData(std::string const & data){
	if (data.empty())
		return ;
	this->_data_parsed.clear();

	char		buffer[32];
	std::string	out;
	FILE		*stream;
//
	stream = popen("ps -Ao user,uid,comm,pid,pcpu,tty -r | head -n 6", "r");
	if (stream)
	{
		while (!feof(stream))
            if (fgets(buffer, 32, stream) != NULL) out.append(buffer);
        pclose(stream);
    }
    // obalagur          5400 /Applications/iT 51161   4.6
    std::string proc = data.substr(0, data.find("sleeping") + 8);
	this->_data_parsed.push_back(proc);
	this->_data_parsed.push_back("----------------------------------------------");
	int lineSize = 52;
	if (out.size() < 290)
		return ;
    std::string title = out.substr(0, lineSize);
	this->_data_parsed.push_back(title);

    std::string line = out.substr(lineSize + 4, 51);
	this->_data_parsed.push_back(line);
	lineSize *= 2;
	line = out.substr(lineSize + 14, 51);
	this->_data_parsed.push_back(line);
	lineSize *= 2;
	line = out.substr(lineSize + 31, 51);
	this->_data_parsed.push_back(line);
}

std::vector<std::string>
BonusModule::getData(void) const{
	return (_data_parsed);
}

int
BonusModule::getIntData(void) const{
	return (_data_int_parsed);
}