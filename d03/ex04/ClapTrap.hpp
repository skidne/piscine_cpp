#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class ClapTrap {

public:

	ClapTrap();
	ClapTrap(ClapTrap & r);
	virtual ~ClapTrap();

	ClapTrap & operator=(ClapTrap & r);

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

	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);
	
};

#endif