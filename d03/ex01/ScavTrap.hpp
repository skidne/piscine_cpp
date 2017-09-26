#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "FragTrap.hpp"

class ScavTrap : public FragTrap {

public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap & r);
	~ScavTrap();

	ScavTrap &	operator=(ScavTrap & r);

	void	init(std::string name);
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	challengeNewcomer();

private:
	using FragTrap::vaulthunter_dot_exe;
	
};

#endif