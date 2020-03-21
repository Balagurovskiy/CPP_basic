

#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(1);
	sp.addNumber(11);
	sp.addNumber(9);
	sp.addNumber(2);
	sp.addNumber(9);
	TRYCATCH(
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		,
		"Not enough elements"
	)
}