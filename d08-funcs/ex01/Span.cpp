

#include "Span.hpp"

Span::Span()
{
	_n = 0;
}

Span::Span
	(unsigned int n)
{
	_n = n;
}

Span::Span
	(const Span & obj)
{
	*this = obj;
}

Span &
	Span::operator =
			(Span const & obj)
{
	this->_list = obj._list;
	this->_n = obj._n;
	return (*this);
}

Span::~Span()
{
}

void
	Span::addNumber
		(int d)
{
	TRYCATCH(
		if (_list.size() == _n)
			throw std::exception();
		_list.push_back(d);
		,
		"list is full"
	)
}

int
	Span::shortestSpan()
{
	if (_list.size() <= 1)
		throw std::exception();
	std::list<int>					list_temp = _list;
	list_temp.sort();
	int shortest = *(--list_temp.end());
	std::list<int>::const_iterator	it = list_temp.begin();
	std::list<int>::const_iterator	it_next = list_temp.begin();
	it_next++;
	while (it_next != list_temp.end()){
		if (*it_next - *it < shortest)
			shortest = *it_next - *it;
		it_next++;
		it++;
	}

	return (shortest);
}

int
Span::longestSpan()
{
	if (_list.size() <= 1)
		throw std::exception();
	int min = *std::min_element(_list.begin(), _list.end());
	int max = *std::max_element(_list.begin(), _list.end());
	return (max - min);
}





