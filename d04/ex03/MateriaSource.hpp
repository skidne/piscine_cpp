#ifndef MATERIASOURCE
#define MATERIASOURCE

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:

	AMateria *mater[4];
	static int index;

	MateriaSource();
	MateriaSource(MateriaSource & r);
	~MateriaSource();

	MateriaSource & operator=(MateriaSource & r);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
	
};

#endif