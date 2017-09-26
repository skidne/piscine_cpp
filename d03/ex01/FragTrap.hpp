#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class FragTrap {

public:

	FragTrap();
	FragTrap(FragTrap & fr);
	FragTrap(std::string name);
	~FragTrap();

	FragTrap & operator=(FragTrap & r);

	int	hitP;
	int	maxHitP;
	int	energyP;
	int	maxEnergyP;
	int	level;
	std::string	name;
	int	meleeAttackDmg;
	int	rangedAttackDmg;
	int	specialAttack;
	int armorDmgReduct;

	void	init(std::string name);
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	vaulthunter_dot_exe(std::string const & target);

};

#endif
