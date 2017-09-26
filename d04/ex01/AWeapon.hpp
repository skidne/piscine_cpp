#ifndef AWEAPON_H
#define AWEAPON_H

#include <iostream>
#include <string>

class AWeapon {

private:

	std::string	_name;
	int			_APcost;
	int			_DMG;

public:

	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon();
	AWeapon(AWeapon & r);
	virtual ~AWeapon();

	AWeapon &	operator=(AWeapon & r);

	std::string const	getName() const;
	int			getAPCost() const;
	int			getDamage() const;
	void	setName(std::string const & name);
	void	setAPCost(int ap);
	void	setDamage(int damage);
	virtual void attack() const = 0;

};

#endif