#include <vector>
#include <iostream>
#include "easyfind.hpp"



int main()
{
	std::vector<int> v;

	int i = -1;
	while(++i < 5)
		v.push_back(i);
	TRYCATCH(
			COUT(easyfind(v, 1))
			COUT(easyfind(v, 5))
			)
	return (0);
}