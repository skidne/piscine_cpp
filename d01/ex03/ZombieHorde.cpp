#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : nr_z(N)
{
	std::srand(std::time(NULL));
	std::string names[] = {"Rick", "Morty", "Harry", "Gregory", "Hermione", "Paul"};

	this->zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		this->zombies[i].name = names[rand() % 6];
		this->zombies[i].type = "stormtrooper";
	}
	std::cout << "Horde appeared." << std::endl;
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->zombies;
	std::cout << "Horde destroyed." << std::endl;
	return ;
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < this->nr_z; i++)
		this->zombies[i].announce();
}
