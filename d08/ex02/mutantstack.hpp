#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

template <typename T>
class MutantStack : virtual public std::vector<T>, virtual public std::stack<T> {

public:

	void	push(T const n)
	{
		this->push_back(n);
	}

	void	pop()
	{
		this->pop_back();
	}

	T		top()
	{
		return *(this->end() - 1);
	}

	int		size()
	{
		return std::vector<T>::size();
	}

};

#endif