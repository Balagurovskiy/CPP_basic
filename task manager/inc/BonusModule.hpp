//
// Created by Olexiy BALAGUROVSKIY on 2019-07-06.
//

#ifndef BOUNUSMODULE_HPP
# define BOUNUSMODULE_HPP

# include "IMonitorModule.hpp"
# include <iostream>
#include <vector>
#include <string>

class	BonusModule : public IMonitorModule
{
public:
	BonusModule(void);
	BonusModule(BonusModule const & src);
	BonusModule		&operator=(BonusModule const & src);
	virtual ~BonusModule(void);

	virtual	void						setData(std::string const &);
	virtual std::vector<std::string> 	getData(void) const;
	virtual int 						getIntData(void) const;

private:
	std::vector<std::string> 	_data_parsed;
	int 						_data_int_parsed;
};

#endif
