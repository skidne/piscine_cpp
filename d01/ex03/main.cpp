#include "ZombieHorde.hpp"

int		main(void)
{
	std::cout << "Area clear." << std::endl;
	ZombieHorde	horde(10);
	horde.announce();
	std::cout << "Area unsafe." << std::endl;
	return 1;
}