//
// Created by Olexiy BALAGUROVSKIY on 2019-07-06.
//

#ifndef RAMMMODULE_HPP
# define RAMMMODULE_HPP

# include "IMonitorModule.hpp"
# include <iostream>
#include <vector>
#include <string>

class	RamModule : public IMonitorModule
{
public:
	RamModule(void);
	RamModule(RamModule const & src);
	RamModule		&operator=(RamModule const & src);
	virtual ~RamModule(void);

	virtual	void						setData(std::string const &);
	virtual std::vector<std::string> 	getData(void) const;
	virtual int 						getIntData(void) const;

private:
	std::vector<std::string> 	_data_parsed;
	int 						_data_int_parsed;
};

#endif
