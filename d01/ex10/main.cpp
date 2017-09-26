#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <cerrno>

bool	is_file(const char* path)
{
	struct stat buf;

	stat(path, &buf);
	return S_ISREG(buf.st_mode);
}

bool	is_dir(const char* path)
{
	struct stat buf;

	stat(path, &buf);
	return S_ISDIR(buf.st_mode);
}

void	wait_input()
{
	std::string	line;

	while (std::getline(std::cin, line))
		std::cout << line << std::endl;
}

void	go_cat(int ac, char **av)
{
	std::ifstream	in;
	char			c;

	for(int i = 1; i < ac; i++)
	{
		in.open(av[i]);
		if (errno == EACCES)
			std::cout	<< "cato9tails: " << av[i] << ": Permission denied"
						<< std::endl;
		else if (!in.is_open())
			std::cout	<< "cato9tails: " << av[i] << ": No such file or directory"
						<< std::endl;
		else if (is_dir(av[i]))
			std::cout	<< "cato9tails: " << av[i] << ": Is a directory"
						<< std::endl;
		else if (is_file(av[i]))
			while (in.get(c))
				std::cout << c;
		in.close();
	}
}

int		main(int ac, char **av)
{
	if (ac < 2)
		wait_input();
	else
		go_cat(ac, av);
	return 1;
}
