#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>

template <typename T>
class Array {

private:

	T				*_arr;
	unsigned int	_len;

public:

	Array <T> () : _arr(NULL), _len(0) {}

	Array <T> (unsigned int n) : _arr(new T[n]), _len(n) {}

	Array <T> (Array & r)
	{
		*this = r;
	}

	~Array <T> ()
	{
		if (this->_arr)
			delete [] this->_arr;
	}

	T &		operator[](unsigned int n)
	{
		if (n >= this->size())
			throw std::exception();
		return this->_arr[n];
	}

	Array &	operator=(Array<T> & r)
	{
		if (this->size())
			delete [] this->_arr;
		this->_arr = new T[r.size()];
		this->_len = r.size();
		for (int i = 0; i < this->size(); i++)
			this->_arr[i] = r[i];
	}

	unsigned int	size() const
	{
		return this->_len;
	}
	
};

#endif
