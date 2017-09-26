#ifndef NINJATRAP_H
#define NINJATRAP_H

#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

public:

	NinjaTrap();
	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap & r);
	~NinjaTrap();

	NinjaTrap &	operator=(NinjaTrap & r);

	void	init(std::string name);
	void	ninjaShoebox(NinjaTrap & r);
	void	ninjaShoebox(FragTrap & r);
	void	ninjaShoebox(ScavTrap & r);
	void	ninjaShoebox(ClapTrap & r); 

};

#endif