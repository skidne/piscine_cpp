#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{
	this->name = "Robert";
	this->title = "the Magnificent";

	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title)
{
	std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer & r)
{
	this->name = r.name;
	this->title = r.title;
}

Sorcerer::~Sorcerer()
{
	std::cout	<< this->name << ", " << this->title << ", is dead."
				<< " Consequences will never be the same !" << std::endl;
}

Sorcerer & Sorcerer::operator=(Sorcerer & r)
{
	this->name = r.name;
	this->title = r.title;

	return *this;
}

void	Sorcerer::polymorph(Victim const & r)
{
	r.getPolymorphed();
}

std::ostream &	operator<<(std::ostream & o, Sorcerer const & r)
{
	o << r.name << ", " << r.title << ", and I like ponies !" << std::endl;
	return o;
}
