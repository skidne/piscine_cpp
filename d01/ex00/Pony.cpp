#include "Pony.hpp"

Pony::Pony(int hp, int mana) : _hp(hp), _mana(mana)
{
	std::cout	<< "The pony with " << this->_hp << " HP and " << this->_mana
				<< " mana was spawned." << std::endl;
	return ;
}

Pony::~Pony(void)
{
	std::cout	<< "The pony with " << this->_hp << " HP and " << this->_mana
				<< " mana was eliminated." << std::endl;
	return ;
}

int		Pony::getHP(void)
{
	return this->_hp;
}

int		Pony::getMana(void)
{
	return this->_mana;
}
