#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
{
	this->hitP = 0;
	this->maxHitP = 0;
	this->energyP = 0;
	this->maxEnergyP = 0;
	this->level = 0;
	this->name = "NinjaTrap";
	this->meleeAttackDmg = 0;
	this->rangedAttackDmg = 0;
	this->specialAttack = 0;
	this->armorDmgReduct = 0;

	std::cout << "A wild NinjaTrap appeared" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name)
{
	std::cout << "A strange " << name << " appeared" << std::endl;
	this->init(name);
}

NinjaTrap::NinjaTrap(NinjaTrap & r)
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

	std::cout << "Copy NinjaTrap constructor called" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "A strange " << this->name << " was destroyed" << std::endl;
}

NinjaTrap &	NinjaTrap::operator=(NinjaTrap & r)
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

void	NinjaTrap::init(std::string name)
{
	this->hitP = 60;
	this->maxHitP = 60;
	this->energyP = 120;
	this->maxEnergyP = 120;
	this->level = 1;
	this->name = name;
	this->meleeAttackDmg = 60;
	this->rangedAttackDmg = 5;
	this->specialAttack = 20;
	this->armorDmgReduct = 0;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap & r)
{
	std::cout << this->name << " takes a baseball bat and beats " << r.name << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap & r)
{
	std::cout << this->name << " joins " << r.name << " in bed" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap & r)
{
	std::cout << this->name << " is aiming at " << r.name << " with a dildo" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap & r)
{
	std::cout << this->name << " sits on " << r.name << "\'s face" << std::endl;
}
