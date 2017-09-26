#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
{
	this->setType("Super Mutant");
	this->setHP(170);
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant & r)
{
	setType(r.getType());
	setHP(r.getHP());
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant & SuperMutant::operator=(SuperMutant & r)
{
	setType(r.getType());
	setHP(r.getHP());

	return *this;
}

void		SuperMutant::takeDamage(int i)
{
	if (this->getHP() < 0)
		this->setHP(this->getHP() - i + 3);
}
