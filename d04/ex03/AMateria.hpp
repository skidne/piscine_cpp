#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>

class ICharacter;

class AMateria {

private:

	std::string		type_;
	unsigned int xp_;	

public:

	AMateria(std::string const & type);
	AMateria();
	AMateria(AMateria & r);
	virtual ~AMateria();

	AMateria & operator=(AMateria & r);

	std::string const & getType() const;
	unsigned int getXP() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};

#endif