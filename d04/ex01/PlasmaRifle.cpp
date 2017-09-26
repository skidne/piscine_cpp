#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
{
	this->setName("Plasma Rifle");
	this->setAPCost(5);
	this->setDamage(21);
}

PlasmaRifle::PlasmaRifle(PlasmaRifle & r)
{
	this->setName(r.getName());
	this->setAPCost(r.getAPCost());
	this->setDamage(r.getDamage());
}

PlasmaRifle::~PlasmaRifle()
{}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle & r)
{
	this->setName(r.getName());
	this->setAPCost(r.getAPCost());
	this->setDamage(r.getDamage());

	return *this;
}

void	PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
