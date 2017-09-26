#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : name(name), type(type)
{
	std::cout << this->name << " was spawned." << std::endl;
	return ;
}

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
