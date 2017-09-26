#ifndef SORCERER_H
#define SORCERER_H

#include "Victim.hpp"

class Sorcerer {

public:

	Sorcerer();
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer & r);
	~Sorcerer();

	Sorcerer & operator=(Sorcerer & r);

	std::string name;
	std::string title;

	void polymorph(Victim const &);

};

std::ostream &	operator<<(std::ostream & o, Sorcerer const & r);

#endif