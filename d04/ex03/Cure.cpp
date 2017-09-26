#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(std::string const & type) : AMateria(type)
{}

Cure::Cure(Cure & r) : AMateria(r.getType())
{}

Cure::~Cure() {}

Cure & Cure::operator=(Cure & r) 
{
	(void)r;
	return *this;
}

AMateria * Cure::clone() const
{
	AMateria * a = new AMateria("cure");

	return a;
}

void		Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	AMateria::use();
}
