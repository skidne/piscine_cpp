#include "Array.hpp"

std::string		string_generator(const int len)
{
	static const char a[] = "abcdefghijklmnopqrstuvwxyz";

	char		s[len];
	for (int i = 0; i < len; ++i)
		s[i] = a[rand() % (sizeof(a) - 1)];
	s[len] = '\0';
	return std::string(s);
}

int		main()
{
	Array<int> arri(5);
	Array<float> arrf(5);
	Array<std::string> arrs(5);

	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		arri[i] = rand() % 1000;
		arrf[i] = static_cast<float>((rand() % 1000)) / (rand() % 100);
		arrs[i] = string_generator(rand() % 10 + 1);
	}

	std::cout << "int array:" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << arri[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "float array:" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << arrf[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "string array:" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "\"" << arrs[i] << "\" ";
	std::cout << std::endl << std::endl;

	std::cout << "catching exception:" << std::endl;
	try
	{
		std::cout << arri[5] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "index out of boundary" << std::endl;
	}

	return 0;
}
