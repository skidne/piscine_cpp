#ifndef YEASYFIND_H
#define YEASYFIND_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <exception>

template <typename T>
int			easyfind(T & container, int val)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), val);

	if (it == container.end())
		throw "Not found";
	return *it;
}

#endif