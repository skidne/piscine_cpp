//
// Created by Alen BADRAJAN on 7/25/17.
//
#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	OUT << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator &f)
{
	(void)f;
	OUT << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
	OUT << "I’ll be back ..." << std::endl;
}

AssaultTerminator &AssaultTerminator::operator=(AssaultTerminator &r)
{
	(void)r;
	return *this;
}

void AssaultTerminator::battleCry() const
{
	OUT << "This code is unclean. PURIFY IT !" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	OUT << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
	OUT << "* attacks with chainfists *" << std::endl;
}

ISpaceMarine *AssaultTerminator::clone() const
{
	AssaultTerminator const *t = this;

	return (ISpaceMarine *) t;
}
