#include "Victim.hpp"

Victim::Victim()
{
	this->name = "Jimmy";

	std::cout << "Some random victim called " << this->name << " just popped !" << std::endl;
}

Victim::Victim(std::string name) : name(name)
{
	std::cout << "Some random victim called " << this->name << " just popped !" << std::endl;
}

Victim::Victim(Victim & r)
{
	this->name = r.name;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->name << " just died for no apparent reason !" << std::endl;
}

void	Victim::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a cute little sheep !" << std::endl;
}

Victim & Victim::operator=(Victim & r)
{
	this->name = r.name;

	return *this;
}

std::ostream &	operator<<(std::ostream & o, Victim const & r)
{
	o << "I'm " << r.name << " and I like otters !" << std::endl;
	return o;
}
