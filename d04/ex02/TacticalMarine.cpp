//
// Created by Alen BADRAJAN on 7/25/17.
//

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	OUT << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine &f)
{
	(void)f;
	OUT << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
    OUT << "Aaargh ..." << std::endl;
}

TacticalMarine &TacticalMarine::operator=(TacticalMarine &r)
{
	(void)r;
	return *this;
}

ISpaceMarine *TacticalMarine::clone() const
{
	TacticalMarine const *t = this;

	return (ISpaceMarine *) t;
}

void TacticalMarine::battleCry() const
{
    OUT << "For the holy PLOT !" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
	OUT << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
	OUT << "* attacks with chainsword *" << std::endl;
}
