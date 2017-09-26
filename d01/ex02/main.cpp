#include "ZombieEvent.hpp"

int		main(void)
{
	std::cout << "Area clear." << std::endl;
	Zombie	z1("Severus", "deadly");
	Zombie*	z2 = new Zombie("Samwell", "peaceful");
	z1.announce();
	ZombieEvent*	e1 = new ZombieEvent();
	e1->setZombieType("stormtrooper");
	Zombie*		greenhorn = e1->newZombie("Karl");
	greenhorn->announce();
	delete greenhorn;
	e1->randomChump();
	delete e1;
	delete z2;
	std::cout << "Area clearing." << std::endl;
	return 1;
}