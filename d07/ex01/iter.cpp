#include <iostream>
#include <cstring>

template <typename T>
void	iter(T * arr, int len, T (*f)(T))
{
	for (int i = 0; i < len; i++)
		arr[i] = (*f)(arr[i]);
}

template <typename T>
T		func1(T elem)
{
	return static_cast<T>(elem - 10);
}

template <typename T>
T		func2(T elem)
{
	return static_cast<T>(elem + 1);
}

int		main()
{
	int		arri[] = {32, 41, 43, -23, 4, 42};
	float	arrf[] = {4.43, 40.43, -32123.43, -32, 0.0, 2.0};
	char	arrs[] = "abcdef";

	std::cout << "Integer array before iter:" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << arri[i] << " ";
	std::cout << std::endl;

	iter(arri, 6, &func2);

	std::cout << "Integer array after iter - func2:" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << arri[i] << " ";
	std::cout << std::endl;

	std::cout << "Float array before iter:" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << arrf[i] << " ";
	std::cout << std::endl;

	iter(arrf, 6, &func1);

	std::cout << "Float array after iter - func1:" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << arrf[i] << " ";
	std::cout << std::endl;

	std::cout << "Char array before iter:" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << arrs[i] << " ";
	std::cout << std::endl;

	iter(arrs, 6, &func2);

	std::cout << "Char array after iter - func2:" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << arrs[i] << " ";
	std::cout << std::endl;

	return 0;
}
