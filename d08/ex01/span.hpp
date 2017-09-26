#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstdlib>

class Span {

private:

	unsigned int		_len;
	std::vector<int>	_arr;

public:

	Span();
	Span(unsigned int const n);
	Span(Span const & r);
	~Span();

	Span & operator=(Span const & r);

	void	addNumber(int const nr);
	void	addNumberRange(std::vector<int> & v2);
	int		shortestSpan();
	int		longestSpan();

	std::vector<int>	getArray() const;
	unsigned int		getLength() const;
	
};

#endif