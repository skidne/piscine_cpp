#ifndef PLASMARIFLE_H
#define PLASMARIFLE_H

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:

	PlasmaRifle();
	PlasmaRifle(PlasmaRifle & r);
	~PlasmaRifle();

	PlasmaRifle & operator=(PlasmaRifle & r);

	void	attack() const;
	
};

#endif