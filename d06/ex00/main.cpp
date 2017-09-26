#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <limits>
#include <cmath>
#include <cfloat>
#include <cctype>

std::string		display_char(double & nr)
{
	std::string	ret = "char: ";

	if (nr < 32)
		ret += "Non displayable";
	else if (nr < 127)
	{
		std::stringstream ss;
		std::string ret2;
		ss << static_cast<char>(nr);
		ss >> ret2;
		ret += "\'" + ret2 + "\'";
	}
	else
		ret += "impossible";

	return ret;
}

std::string	display_int(double & nr)
{
	std::string	ret = "int: ";

	if (nr > INT_MAX || nr < INT_MIN || isnan(nr))
		ret += "impossible";
	else
	{
		std::stringstream	ss;
		std::string			ret2;
		ss << static_cast<int>(nr);
		ss >> ret2;
		ret += ret2;
	}
	return ret;
}

std::string	display_float(double & nr)
{
	std::string	ret = "float: ";
	std::stringstream	ss;
	std::string			ret2;
	ss << static_cast<float>(nr);
	ss >> ret2;
	ret += ret2;

	if (ret2.find('.') == std::string::npos && !isalpha(ret2[ret2.length() - 1]))
		ret += ".0";
	ret += "f";
	return ret;
}

std::string	display_double(double & nr)
{
	std::string	ret = "double: ";
	std::stringstream	ss;
	std::string			ret2;
	ss << nr;
	ss >> ret2;
	ret += ret2;

	if (ret2.find('.') == std::string::npos && !isnan(nr) &&
		!isalpha(ret2[ret2.length() - 1]))
		ret += ".0";
	return ret;
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return 0;

	double		nr = atof(av[1]);

	std::cout << display_char(nr) << std::endl;
	std::cout << display_int(nr) << std::endl;
	std::cout << display_float(nr) << std::endl;
	std::cout << display_double(nr) << std::endl;
	
	return 1;
}
