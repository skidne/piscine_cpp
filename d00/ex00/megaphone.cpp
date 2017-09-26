#include <iostream>

void	uppercase(char *av)
{
	int	j = -1;

	while (av[++j])
	{
		if (av[j] >= 'a' && av[j] <= 'z')
			av[j] -= 32;
		std::cout << av[j];
	}
}

void	upperino(int ac, char **av)
{
	int	i = 0;

	while (++i < ac)
		uppercase(av[i]);
	std::cout << std::endl;
}

int		main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		upperino(ac, av);
	return (1);
}