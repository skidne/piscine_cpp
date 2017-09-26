#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
{
	this->setType("RadScorpion");
	this->setHP(80);
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion & r)
{
	setType(r.getType());
	setHP(r.getHP());
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion & RadScorpion::operator=(RadScorpion & r)
{
	setType(r.getType());
	setHP(r.getHP());

	return *this;
}

