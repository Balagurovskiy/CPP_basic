//
// Created by Olexiy BALAGUROVSKIY on 2019-07-06.
//

#ifndef CPUMMODULE_HPP
# define CPUMMODULE_HPP

# include "IMonitorModule.hpp"
# include <iostream>
#include <vector>
#include <string>

class	CpuModule : public IMonitorModule
{
public:
	CpuModule(void);
	CpuModule(CpuModule const & src);
	CpuModule		&operator=(CpuModule const & src);
	virtual ~CpuModule(void);

	virtual	void						setData(std::string const &);
	virtual std::vector<std::string> 	getData(void) const;
	virtual int 						getIntData(void) const;

private:
	std::vector<std::string> 	_data_parsed;
	int 						_data_int_parsed;
};

#endif
