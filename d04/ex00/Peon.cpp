#include "Peon.hpp"

Peon::Peon() : Victim("Joe")
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon & r)
{
	this->name = r.name;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

void	Peon::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a pink pony !" << std::endl;
}

Peon & Peon::operator=(Peon & r)
{
	this->name = r.name;

	return *this;
}

std::ostream &	operator<<(std::ostream & o, Peon const & r)
{
	o << "I'm " << r.name << " and I like otters !" << std::endl;
	return o;
}
