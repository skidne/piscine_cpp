#ifndef CHARACTER_H
#define CHARACTER_H

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {

private:

	std::string	_name;
	int			_AP;
	AWeapon * 	_weapon;

public:

	Character(std::string const & name);
	Character();
	Character(Character & r);
	~Character();

	Character & operator=(Character & r);

	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);


	std::string const getName() const;
	int			getAP() const;
	AWeapon*		getWeapon() const;

	void		setName(std::string const & name);
	void		setAP(int ap);
	void		setWeapon(AWeapon*);

};

std::ostream &	operator<<(std::ostream & o, Character const & r);

#endif