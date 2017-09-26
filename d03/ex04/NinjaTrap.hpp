#ifndef NINJATRAP_H
#define NINJATRAP_H

#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap {

public:

	NinjaTrap();
	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap & r);
	~NinjaTrap();

	NinjaTrap &	operator=(NinjaTrap & r);

	virtual void	rangedAttack(std::string const & target);
	virtual void	meleeAttack(std::string const & target);

	void	init(std::string name);
	virtual void	ninjaShoebox(NinjaTrap & r);
	virtual void	ninjaShoebox(FragTrap & r);
	virtual void	ninjaShoebox(ScavTrap & r);
	virtual void	ninjaShoebox(ClapTrap & r); 

};

#endif