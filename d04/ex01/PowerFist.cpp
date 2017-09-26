#include "PowerFist.hpp"

PowerFist::PowerFist()
{
	setName("Power Fist");
	setAPCost(8);
	setDamage(50);
}

PowerFist::PowerFist(PowerFist & r)
{
	setName(r.getName());
	setAPCost(r.getAPCost());
	setDamage(r.getDamage());
}

PowerFist::~PowerFist()
{}

PowerFist & PowerFist::operator=(PowerFist & r)
{
	setName(r.getName());
	setAPCost(r.getAPCost());
	setDamage(r.getDamage());

	return *this;
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
