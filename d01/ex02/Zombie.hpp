#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {

public:

	Zombie(std::string name, std::string type);
	~Zombie();
	
	void	announce(void);

	std::string	name;
	std::string	type;

};

#endif