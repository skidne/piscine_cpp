#include "Zombie.hpp"

Zombie::Zombie(void)
{ return ; }

Zombie::~Zombie(void)
{
	std::cout << this->name << "\'s brains were smashed." << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout	<< "<" << this->name << " (" << this->type << ")> BRAAAIINNNSSS!"
				<< std::endl;
}
