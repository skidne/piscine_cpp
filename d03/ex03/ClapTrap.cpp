#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->hitP = 0;
	this->maxHitP = 0;
	this->energyP = 0;
	this->maxEnergyP = 0;
	this->level = 0;
	this->name = "ClapTrap";
	this->meleeAttackDmg = 0;
	this->rangedAttackDmg = 0;
	this->specialAttack = 0;
	this->armorDmgReduct = 0;

	std::cout << "A wild ClapTrap appeared" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap & r)
{
	this->hitP = r.hitP;
	this->maxHitP = r.maxHitP;
	this->energyP = r.energyP;
	this->maxEnergyP = r.maxEnergyP;
	this->level = r.level;
	this->name = r.name;
	this->meleeAttackDmg = r.meleeAttackDmg;
	this->rangedAttackDmg = r.rangedAttackDmg;
	this->specialAttack = r.specialAttack;
	this->armorDmgReduct = r.armorDmgReduct;

	std::cout << "Copy ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "A wild ClapTrap was destroyed" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap & r)
{
	this->hitP = r.hitP;
	this->maxHitP = r.maxHitP;
	this->energyP = r.energyP;
	this->maxEnergyP = r.maxEnergyP;
	this->level = r.level;
	this->name = r.name;
	this->meleeAttackDmg = r.meleeAttackDmg;
	this->rangedAttackDmg = r.rangedAttackDmg;
	this->specialAttack = r.specialAttack;
	this->armorDmgReduct = r.armorDmgReduct;

	return *this;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hitP -= (amount - this->armorDmgReduct);
	if (this->hitP < 1)
	{
		this->hitP = 0;
		std::cout << this->name << " was destroyed" << std::endl;
	}
	else
		std::cout << this->name << " took " << amount << " damage points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->hitP += amount;
	if (this->hitP > this->maxHitP)
	{
		this->hitP = this->maxHitP;
		std::cout << this->name << " is at max health" << std::endl;
	}
	else
		std::cout << this->name << " repaired " << amount << " health points" << std::endl;
}
