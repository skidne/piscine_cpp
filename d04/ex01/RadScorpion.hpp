#ifndef RADSCORPION_H
#define RADSCORPION_H

#include "Enemy.hpp"

class RadScorpion : public Enemy {

public:

	RadScorpion();
	RadScorpion(RadScorpion & r);
	virtual ~RadScorpion();

	RadScorpion & operator=(RadScorpion & r);
	
};

#endif