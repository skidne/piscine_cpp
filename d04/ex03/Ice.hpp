#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria {

public:

	Ice();
	Ice(Ice & r);
	~Ice();

	Ice & operator=(Ice & r);

	AMateria * clone() const;

	void use(ICharacter& target);

};

#endif