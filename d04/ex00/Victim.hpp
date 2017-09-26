#ifndef VICTIM_H
#define VICTIM_H

#include <iostream>
#include <string>

class Victim {

public:

	Victim();
	Victim(std::string name);
	Victim(Victim & r);
	~Victim();

	Victim & operator=(Victim & r);

	std::string name;

	virtual void	getPolymorphed() const;
	
};

std::ostream &	operator<<(std::ostream & o, Victim const & r);

#endif