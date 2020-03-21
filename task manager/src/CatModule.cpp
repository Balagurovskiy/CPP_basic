//
// Created by Olexiy BALAGUROVSKIY on 2019-07-06.
//

# include "CatModule.hpp"


CatModule::CatModule(){
	this->_data_int_parsed = 0;
	this->_data_parsed.push_back("* * * * *");
	this->_data_parsed.push_back("* * * * *");
	this->_data_parsed.push_back("CAT for ZAZ");
	this->_data_parsed.push_back("* * * * *");
	this->_data_parsed.push_back("* * * * *");
}

CatModule::CatModule(CatModule const & src){
	*this = src;
}

CatModule	&
CatModule::operator = (CatModule const & src){
	this->_data_parsed.clear();
	this->_data_int_parsed = src._data_int_parsed;
	for (int i = 0; i < src._data_parsed.size(); ++i) {
		this->_data_parsed.push_back(src._data_parsed.at(i));
	}
	return (*this);
}

CatModule::~CatModule(void){
}

void
CatModule::setData(std::string const & data){
	(void) data;
}

std::vector<std::string>
CatModule::getData(void) const{
	return (_data_parsed);
}

int
CatModule::getIntData(void) const{
	return (_data_int_parsed);
}