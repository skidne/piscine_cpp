#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type)
{
	this->type_ = type;
	this->xp_ = 0;
}

AMateria::AMateria()
{
	this->type_ = "default";
	this->xp_ = 0;
}

AMateria::AMateria(AMateria & r)
{
	this->type_ = r.getType();
	this->xp_ = r.getXP();
}

AMateria::~AMateria()
{}

AMateria & AMateria::operator=(AMateria & r)
{
	this->type_ = r.getType();
	this->xp_ = r.getXP();

	return *this;
}

std::string const & AMateria::getType() const
{
	return this->type_;
}

unsigned int	AMateria::getXP() const
{
	return this->xp_;
}

void		AMateria::use(ICharacter & target)
{
	target.getName();
	this->xp_ += 10;
}
