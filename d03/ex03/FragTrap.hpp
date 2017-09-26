#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap();
	FragTrap(FragTrap & fr);
	FragTrap(std::string name);
	~FragTrap();

	FragTrap & operator=(FragTrap & r);

	
	void	init(std::string name);
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);

	void	vaulthunter_dot_exe(std::string const & target);

};

#endif
