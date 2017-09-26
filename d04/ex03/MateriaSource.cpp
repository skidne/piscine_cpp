#include "MateriaSource.hpp"

int		MateriaSource::index = 0;

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->mater[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource & r)
{
	for (int i = 0; i < 4; i++)
		this->mater[i] = r.mater[i];
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i <= index; i++)
		delete this->mater[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource & r)
{
	for (int i = 0; i < 4; i++)
		this->mater[i] = r.mater[i];

	return *this;
}

void		MateriaSource::learnMateria(AMateria * mat)
{
	if (index < 4)
		this->mater[index++] = mat;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i <= index; i++)
		if (this->mater[i]->getType() == type)
			return this->mater[i];
	return 0;
}
