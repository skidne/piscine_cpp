#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria {

public:

	Cure();
	Cure(Cure & r);
	~Cure();

	Cure & operator=(Cure & r);
	
	AMateria * clone() const;

	void use(ICharacter& target);

};

#endif