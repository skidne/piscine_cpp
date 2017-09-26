#include "ZombieEvent.hpp"
#include <cstdlib>
#include <ctime>

ZombieEvent::ZombieEvent(void)
{
	std::cout << "ZombieEvent created." << std::endl;
	return ;
}

ZombieEvent::~ZombieEvent(void)
{
	std::cout << "ZombieEvent destroyed." << std::endl;
	return ;
}

void		ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie*		ZombieEvent::newZombie(std::string name)
{
	Zombie*	coral = new Zombie(name, this->type);
	return coral;
}

void		ZombieEvent::randomChump(void)
{
	std::srand(std::time(NULL));
	std::string names[] = {"Rick", "Morty", "Harry", "Gregory", "Hermione", "Paul"};

	Zombie newZ(names[rand() % 6], this->type);
	newZ.announce();
}