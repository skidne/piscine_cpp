#include "Enemy.hpp"

Enemy::Enemy()
{
	this->setHP(100);
	this->setType("bad");
}

Enemy::Enemy(int hp, std::string const & type)
{
	this->setHP(hp);
	this->setType(type);
}

Enemy::Enemy(Enemy & r)
{
	this->setHP(r.getHP());
	this->setType(r.getType());
}

Enemy::~Enemy()
{}

Enemy & Enemy::operator=(Enemy & r)
{
	this->setHP(r.getHP());
	this->setType(r.getType());

	return *this;
}

std::string	const Enemy::getType() const
{
	return this->_type;
}

int			Enemy::getHP() const
{
	return this->_hp;
}

void		Enemy::setHP(int hp)
{
	this->_hp = hp;
}

void		Enemy::setType(std::string const typ)
{
	this->_type = typ;
}

void		Enemy::takeDamage(int i)
{
	if (this->getHP() > 0)
		this->setHP(this->getHP() - i);
}
