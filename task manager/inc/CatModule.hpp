//
// Created by Olexiy BALAGUROVSKIY on 2019-07-06.
//

#ifndef CATMODULE_HPP
# define CATMODULE_HPP

# include "IMonitorModule.hpp"
# include <iostream>
#include <vector>
#include <string>

class	CatModule : public IMonitorModule
{
public:
	CatModule(void);
	CatModule(CatModule const & src);
	CatModule		&operator=(CatModule const & src);
	virtual ~CatModule(void);

	virtual	void						setData(std::string const &);
	virtual std::vector<std::string> 	getData(void) const;
	virtual int 						getIntData(void) const;

private:
	std::vector<std::string> 	_data_parsed;
	int 						_data_int_parsed;
};

#endif
