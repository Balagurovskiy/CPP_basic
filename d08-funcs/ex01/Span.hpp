

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <list>

#define COUT(x) std::cout << x << std::endl;
#define TRYCATCH(x, mssg) try{x}catch (std::exception & e) {COUT(mssg)}

class Span
{
	private:

		std::list<int>	_list;
		unsigned int	_n;

	public:

		Span();
		Span(unsigned int n);
		Span(const Span & obj);

		Span &	operator = (Span const & obj);

		void	addNumber(int d);
		int		shortestSpan();
		int		longestSpan();

		~Span();
};

#endif
