#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(std::string const & type) : AMateria(type)
{}

Ice::Ice(Ice & r) : AMateria(r.getType())
{}

Ice::~Ice() {}

Ice & Ice::operator=(Ice & r) 
{
	(void)r;

	return *this;
}

AMateria * Ice::clone() const
{
	return new AMateria("ice");
}

void		Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use();
}
