#include "Character.hpp"

int Character::index = 0;

Character::Character()
{
	this->name = "char";
	for (int i = 0; i < 4; i++)
		mater[i] = NULL;
}

Character::Character(std::string const & name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		mater[i] = NULL;
}

Character::Character(Character & r)
{
	this->name = r.getName();
	for (int i = 0; i < 4; i++)
		this->mater[i] = r.mater[i];
}

Character::~Character()
{
	for (int i = 0; i <= index; i++)
		delete mater[i];
	index = 0;
}

Character & Character::operator=(Character & r)
{
	this->name = r.getName();
	for (int i = 0; i < 4; i++)
		this->mater[i] = r.mater[i];

	return *this;
}

std::string const & Character::getName() const
{
	return this->name;
}

void		Character::equip(AMaterial * mat)
{
	if (index < 3)
		mater[index++] = mat;
}

void		Character::unequip(int ind)
{
	if (ind < 3 && ind > 0)
		this->mater[ind] = NULL;
}

void		Character::use(int ind, ICharacter & target)
{
	this->mater[ind]->use(target);
}
