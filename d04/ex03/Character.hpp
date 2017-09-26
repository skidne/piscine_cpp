#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

class Character : public ICharacter {

public:

	AMateria *mater[4];
	static	int index;

	std::string	name;

	Character();
	Character(std::string const & name);
	Character(Character & r);
	~Character();

	Character & operator=(Character & r);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	
};

#endif