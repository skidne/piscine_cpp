#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	this->_name = name;
	this->_APcost = apcost;
	this->_DMG = damage;
}

AWeapon::AWeapon()
{
	this->_name = "kek";
	this->_APcost = 0;
	this->_DMG = 50;
}

AWeapon::AWeapon(AWeapon & r)
{
	this->_name = r.getName();
	this->_APcost = r.getAPCost();
	this->_DMG = r.getDamage();
}

AWeapon::~AWeapon() {}

AWeapon & AWeapon::operator=(AWeapon & r)
{
	this->setName(r.getName());
	this->setAPCost(r.getAPCost());
	this->setDamage(r.getDamage());

	return *this;
}

std::string	const AWeapon::getName() const
{
	return this->_name;
}

int			AWeapon::getAPCost() const
{
	return this->_APcost;
}

int			AWeapon::getDamage() const
{
	return this->_DMG;
}

void		AWeapon::setName(std::string const & name)
{
	this->_name = name;
}

void		AWeapon::setAPCost(int ap)
{
	this->_APcost = ap;
}

void		AWeapon::setDamage(int dmg)
{
	this->_DMG = dmg;
}
