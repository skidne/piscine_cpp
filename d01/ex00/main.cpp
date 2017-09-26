#include "Pony.hpp"

void		ponyOnTheStack(void)
{
	Pony	stPony = Pony(45, 90);

	std::cout	<< "The stack pony has " << stPony.getMana()
				<< " mana out of 100." << std::endl;
}

void		ponyOnTheHeap(void)
{
	Pony*	heapPony = new Pony(80, 32);

	std::cout	<< "The heap pony has " << heapPony->getHP()
				<< " HP out of 100." << std::endl;
	delete heapPony;
}

int			main(void)
{
	std::cout << "Begin" << std::endl;
	ponyOnTheStack();
	ponyOnTheHeap();
	std::cout << "The end." << std::endl;
	return (1);
}