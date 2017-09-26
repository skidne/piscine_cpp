#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

#include "Zombie.hpp"
#include <ctime>
#include <cstdlib>

class ZombieHorde {

public:

	ZombieHorde(int N);
	~ZombieHorde();

	Zombie*		zombies;
	int			nr_z;

	void		announce(void);
	
};

#endif