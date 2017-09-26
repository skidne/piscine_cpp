#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:

	FragTrap();
	FragTrap(FragTrap & fr);
	FragTrap(std::string name);
	virtual ~FragTrap();

	FragTrap & operator=(FragTrap & r);

	
	void	init(std::string name);
	virtual void	rangedAttack(std::string const & target);
	virtual void	meleeAttack(std::string const & target);

	void	vaulthunter_dot_exe(std::string const & target);

};

#endif
