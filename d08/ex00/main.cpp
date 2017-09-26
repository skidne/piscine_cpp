#include "easyfind.hpp"

int		main()
{
	std::list<int> lst;
	std::vector<int> v;
	std::map<char, int> map;

	for (int i = 0; i < 10; i++)
	{
		lst.push_back(i);
		v.push_back(i);
		map[i + 'a'] = i;
	}

	try
	{
		std::cout << "easyfind in list for 4:  " << easyfind(lst, 4) << std::endl;
		std::cout << "easyfind in list for 9:  " << easyfind(lst, 9) << std::endl;
		std::cout << easyfind(lst, -1) << std::endl;
	}
	catch (char const * e)
	{
		std::cout << e << std::endl;
	}

	try
	{
		std::cout << "easyfind in vector for 1:  " << easyfind(lst, 1) << std::endl;
		std::cout << "easyfind in vector for 3:  " << easyfind(lst, 3) << std::endl;
		std::cout << easyfind(lst, 10) << std::endl;
	}
	catch (char const * e)
	{
		std::cout << e << std::endl;
	}

	try
	{
		std::cout << "easyfind in map for 2:  " << easyfind(lst, 2) << std::endl;
		std::cout << "easyfind in map for 8:  " << easyfind(lst, 8) << std::endl;
		std::cout << easyfind(lst, 33) << std::endl;
	}
	catch (char const * e)
	{
		std::cout << e << std::endl;
	}

	return 0;
}
