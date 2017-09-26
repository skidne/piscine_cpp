#include <iostream>
#include <string>

template <typename T>
void		swap(T & a, T & b)
{
	T tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T &	min(T & a, T & b)
{
	return b <= a ? b : a;
}

template <typename T>
T &	max(T & a, T & b)
{
	return b >= a ? b : a;
}

int			main()
{
	int		a = 42, b = 21;
	float	af = 0.43f, bf = 432.3f;
	std::string	as = "al", bs = "la";

	std::cout	<< "max(" << a << ", " << b << ") = "
				<< max<int>(a, b) << std::endl;
	std::cout	<< "min(" << af << ", " << bf << ") = "
				<< min<float>(af, bf) << std::endl;
	std::cout	<< "max(\"" << as << "\", \"" << bs << "\") = \""
				<< max<std::string>(as, bs) << "\"" << std::endl;

	std::cout << "swap(" << a << ", " << b << ")" << std::endl;
	swap<int>(a, b);
	std::cout << "swap(" << af << ", " << bf << ")" << std::endl;
	swap<float>(af, bf);
	std::cout << "swap(\"" << as << "\", \"" << bs << "\")" << std::endl;
	swap(as, bs);
	
	std::cout	<< "min(" << a << ", " << b << ") = "
				<< min<int>(a, b) << std::endl;
	std::cout	<< "max(" << af << ", " << bf << ") = "
				<< max<float>(af, bf) << std::endl;
	std::cout	<< "min(\"" << as << "\", \"" << bs << "\") = \""
				<< min<std::string>(as, bs) << "\"" << std::endl;
	return 0;
}
