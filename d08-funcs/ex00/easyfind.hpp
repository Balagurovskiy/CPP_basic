#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

#define COUT(x) std::cout << x << std::endl;
#define TRYCATCH(x) try{x}catch (std::exception & e) {COUT(e.what())}

template<typename T>
int	easyfind(T & container, int value)
{
	for(typename T::iterator it = container.begin(); it != container.end(); ++it){
		if (*it == value)
			return (*it);
	}
	throw std::logic_error("container doesnt have such value ");
}

#endif
