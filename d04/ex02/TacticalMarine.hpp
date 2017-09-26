//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX02_TACTICALMARINE_HPP
#define EX02_TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
public:

	TacticalMarine();
	TacticalMarine(TacticalMarine & f);
	~TacticalMarine();

	TacticalMarine & operator=(TacticalMarine & r);

    ISpaceMarine* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif //EX02_TACTICALMARINE_HPP
