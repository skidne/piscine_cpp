#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {

public:

	Zombie();
	~Zombie();
	
	void	announce(void);

	std::string	name;
	std::string	type;

};

#endif