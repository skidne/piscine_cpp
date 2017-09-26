#ifndef PEON_H
#define PEON_H

#include "Victim.hpp"

class Peon : public Victim {

public:

	Peon();
	Peon(std::string name);
	Peon(Peon & r);
	~Peon();

	Peon & operator=(Peon & r);
	void	getPolymorphed() const;

};

std::ostream &	operator<<(std::ostream & o, Peon const & r);

#endif