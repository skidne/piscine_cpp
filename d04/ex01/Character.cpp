#include "Character.hpp"

Character::Character(std::string const &name)
{
	this->setName(name);
	this->setAP(40);
	this->setWeapon(NULL);
}

Character::Character()
{
	this->setName("Character");
	this->setAP(40);
	this->setWeapon(NULL);
}

Character::Character(Character & r)
{
	this->setName(r.getName());
	this->setAP(r.getAP());
	this->setWeapon(r.getWeapon());
}

Character::~Character()
{}

Character & Character::operator=(Character & r)
{
	this->setName(r.getName());
	this->setAP(r.getAP());
	this->setWeapon(r.getWeapon());

	return *this;
}

std::string const Character::getName() const
{
	return this->_name;
}

int			Character::getAP() const
{
	return this->_AP;
}

AWeapon*		Character::getWeapon() const
{
	return this->_weapon;
}

void		Character::setName(std::string const & name)
{
	this->_name = name;
}

void		Character::setAP(int ap)
{
	this->_AP = ap;
}

void		Character::setWeapon(AWeapon * w)
{
	this->_weapon = w;
}

void		Character::recoverAP()
{
	this->setAP(this->getAP() + 10);
	if (this->getAP() > 40)
		this->setAP(40);
}

void		Character::equip(AWeapon * w)
{
	this->setWeapon(w);
}

void		Character::attack(Enemy * e)
{
	if (this->getWeapon() != NULL && this->getAP() >= this->getWeapon()->getAPCost())
	{
		std::cout	<< this->getName() << " attacks " << e->getType()
					<< " with a " << this->getWeapon()->getName() << std::endl;
		this->getWeapon()->attack();
		e->takeDamage(this->getWeapon()->getDamage());
		this->setAP(this->getAP() - this->getWeapon()->getAPCost());
		if (e->getHP() < 1)
			delete e;
	}
}

std::ostream &	operator<<(std::ostream & o, Character const & r)
{
	if (r.getWeapon() != NULL)
		o	<< r.getName() << " has " << r.getAP() << " AP and wields a "
			<< r.getWeapon()->getName() << std::endl;
	else
		o << r.getName() << " has " << r.getAP() << " AP and is unarmed" << std::endl;

	return o;
}

