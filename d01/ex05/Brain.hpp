#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>
#include <string>
#include <sstream>

class Brain {

public:

	Brain();
	~Brain();
	
	std::string	identify(void) const;

};

#endif