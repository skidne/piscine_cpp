#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
{
	this->hitP = 100;
	this->maxHitP = 100;
	this->energyP = 120;
	this->maxEnergyP = 120;
	this->level = 1;
	this->name = "SuperTrap";
	this->meleeAttackDmg = 60;
	this->rangedAttackDmg = 20;
	this->specialAttack = 70;
	this->armorDmgReduct = 5;

	std::cout << "A keked SuperTrap appeared" << std::endl;
}

SuperTrap::SuperTrap(std::string name)
{
	this->hitP = 100;
	this->maxHitP = 100;
	this->energyP = 120;
	this->maxEnergyP = 120;
	this->level = 1;
	this->name = name;
	this->meleeAttackDmg = 60;
	this->rangedAttackDmg = 20;
	this->specialAttack = 70;
	this->armorDmgReduct = 5;
	std::cout << "A keked " << name << " appeared" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap & r) : ClapTrap(r), FragTrap(r), NinjaTrap(r)
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

	std::cout << "Copy SuperTrap constructor called" << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "A keked " << this->name << " was destroyed" << std::endl;
}

void		SuperTrap::rangedAttack(std::string const & target)
{
	FragTrap::rangedAttack(target);
}

void		SuperTrap::meleeAttack(std::string const & target)
{
	NinjaTrap::meleeAttack(target);
}
