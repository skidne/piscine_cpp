#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>

typedef struct	Data
{
	std::string	s1;
	int			n;
	std::string	s2;
}				Data;

void *	serialize()
{
	char str[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
	char	*ret;

	ret = new char[20];
	srand(time(NULL));
	int *n = new int(rand() % INT_MAX);
	for (int i = 0; i < 17; i++)
	{
		if (i == 8)
			ret[i] = reinterpret_cast<char *>(n)[i - 8];
		else
			ret[i] = str[rand() % strlen(str)];
	}

	std::cout << "\tBefore serializing:" << std::endl;
	std::cout << "s1: " << std::string(ret, 8) << std::endl;
	std::cout << "n:  " << *n << std::endl;
	std::cout << "s2: " << std::string(ret + 12) << std::endl;

	return reinterpret_cast<void *>(ret);
}

Data *	deserialize(void * raw)
{
	Data * dat = new Data;

	dat->s1 = std::string(reinterpret_cast<char *>(raw), 8);
	dat->n = *(reinterpret_cast<int *>(raw) + 8);
	dat->s2 = std::string(reinterpret_cast<char *>(raw) + 12);

	return dat;
}

int		main()
{
	Data * dat = deserialize(serialize());

	std::cout << "\tAfter deserializing:" << std::endl;
	std::cout << "s1: " << dat->s1 << std::endl;
	std::cout << "n:  " << dat->n << std::endl;
	std::cout << "s2: " << dat->s2 << std::endl;

	return 0;
}
