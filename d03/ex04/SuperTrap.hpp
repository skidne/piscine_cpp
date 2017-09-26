#ifndef SUPERTRAP_H
#define SUPERTRAP_H

#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {

public:

	SuperTrap();
	SuperTrap(std::string name);
	SuperTrap(SuperTrap & r);
	~SuperTrap();

	SuperTrap & operator=(SuperTrap & r);

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);

};

#endif