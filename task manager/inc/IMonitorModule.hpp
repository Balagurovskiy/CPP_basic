//
// Created by Olexiy BALAGUROVSKIY on 2019-07-06.
//

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <iostream>

class						IMonitorModule
{
	public:
		virtual	~IMonitorModule(void) {};
		virtual	void						setData(std::string const &)  = 0;
		virtual std::vector<std::string> 	getData(void) const = 0;
		virtual int 						getIntData(void) const = 0;
};

#endif //CLION_RUSH_01_IMONITORMODULE_HPP
