#ifndef POWERFIST_H
#define POWERFIST_H

#include "AWeapon.hpp"

class PowerFist : public AWeapon {

public:

	PowerFist();
	PowerFist(PowerFist & r);
	~PowerFist();

	PowerFist & operator=(PowerFist & r);

	void	attack() const;
	
};

#endif