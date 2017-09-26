#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "A wild FR4G-TP appeared" << std::endl;
	this->init("FR4G-TP");
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "A wild " << name << " appeared" << std::endl;
	this->init(name);
}

FragTrap::FragTrap(FragTrap & r)
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

	std::cout << "Copy FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "A wild " << this->name << " was destroyed" << std::endl;
}

void	FragTrap::init(std::string name)
{
	this->hitP = 100;
	this->maxHitP = 100;
	this->energyP = 100;
	this->maxEnergyP = 100;
	this->level = 1;
	this->name = name;
	this->meleeAttackDmg = 30;
	this->rangedAttackDmg = 20;
	this->specialAttack = 70;
	this->armorDmgReduct = 5;
}

FragTrap &	FragTrap::operator=(FragTrap & r)
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

void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout	<< "FR4G-TP " << this->name << " attacks " << target << " at range, causing " 
				<< this->rangedAttackDmg << " points of damage !" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout	<< "FR4G-TP " << this->name << " attacks " << target << " with melee, causing " 
				<< this->meleeAttackDmg << " points of damage !" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string	attack[] = {"Fart Attack", "Shit Attack", "Mucus Attack", "Flying Attack",
							"Benis Attack"};
	if (this->energyP > 0)
	{
		std::cout	<< this->name << " performs a " << attack[rand() % 5]
					<< " on " << target << std::endl;
		this->energyP -= 25;
	}
	else
		std::cout	<< this->name << " doesn't have enough energy points to perform a special attack"
					<< std::endl;
}
