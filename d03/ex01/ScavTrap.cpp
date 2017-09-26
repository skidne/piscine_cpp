#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->init("ScavTrap");
	std::cout << "A mild ScavTrap appeared" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "A mild " << name << " appeared" << std::endl;
	this->init(name);
}

ScavTrap::ScavTrap(ScavTrap & r)
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

	std::cout << "Copy ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "A mild " << this->name << " was destroyed" << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap & r)
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

void	ScavTrap::init(std::string name)
{
	this->hitP = 100;
	this->maxHitP = 100;
	this->energyP = 50;
	this->maxEnergyP = 50;
	this->level = 1;
	this->name = name;
	this->meleeAttackDmg = 20;
	this->rangedAttackDmg = 15;
	this->specialAttack = 40;
	this->armorDmgReduct = 3;
}

void	ScavTrap::rangedAttack(std::string const & target)
{
	std::cout	<< "ScavTrap " << this->name << " attacks " << target << " at range, causing " 
				<< this->rangedAttackDmg << " points of damage !" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout	<< "ScavTrap " << this->name << " attacks " << target << " with melee, causing " 
				<< this->meleeAttackDmg << " points of damage !" << std::endl;
}

void	ScavTrap::challengeNewcomer()
{
	std::string	challengers[] = {"eat a smelly shoe", "shit on a dance pole", "suck a stick",
								"play with your balls", "stick 5 fingers up your ass, no lube"};

	std::cout << this->name << " challenges newcomers to " << challengers[rand() % 5] << std::endl;
}

