#include "span.hpp"

Span::Span() : _len(0) {}

Span::Span(unsigned int n) : _len(n) {}

Span::Span(Span const & r)
{
	*this = r;
}

Span::~Span() {}

Span &		Span::operator=(Span const & r)
{
	this->_len = r.getLength();
	this->_arr = r.getArray();

	return *this;
}

std::vector<int>	Span::getArray() const
{
	return this->_arr;
}

unsigned int		Span::getLength() const
{
	return this->_len;
}

void			Span::addNumber(int const nr)
{
	if (this->getLength() > this->_arr.size())
		this->_arr.push_back(nr);
	else
		throw "The array is full";
}

void			Span::addNumberRange(std::vector<int> & v2)
{
	if (this->getLength() >= this->_arr.size() + v2.size())
		this->_arr.insert(this->_arr.end(), v2.begin(), v2.end());
	else
		throw "The array will overflow";
}

int				Span::shortestSpan()
{
	if (this->_arr.size() < 2)
		throw "Array too small";

	std::vector<int> v = this->_arr;
	std::sort(v.begin(), v.end());

	int		max = 9999999;

	for (std::vector<int>::iterator it = v.begin(); it < v.end() - 1; ++it)
		if (*(it + 1) - *it < max)
			max = *(it + 1) - *it;

	return max;
}

int				Span::longestSpan()
{
	if (this->_arr.size() < 2)
		throw "Array too small";

	std::vector<int> v = this->_arr;
	std::sort(v.begin(), v.end());

	return *(v.end() - 1) - *(v.begin());
}
