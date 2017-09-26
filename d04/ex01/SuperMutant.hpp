#ifndef SUPERMUTANT_H
#define SUPERMUTANT_H

#include "Enemy.hpp"

class SuperMutant : public Enemy {

public:

	SuperMutant();
	SuperMutant(SuperMutant & r);
	virtual ~SuperMutant();

	SuperMutant & operator=(SuperMutant & r);

	void	takeDamage(int i);
	
};

#endif