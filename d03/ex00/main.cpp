#include "FragTrap.hpp"

int		main()
{
	srand(time(NULL));

	FragTrap player1("Julio");
	FragTrap player2("Petrica");
	FragTrap player3("Glados");

	player1.meleeAttack(player2.name);
	player2.takeDamage(player1.meleeAttackDmg);

	player3.rangedAttack(player1.name);
	player1.takeDamage(player3.rangedAttackDmg);

	player3.vaulthunter_dot_exe(player1.name);
	player1.takeDamage(player3.specialAttack);

	player2.vaulthunter_dot_exe(player3.name);
	player3.takeDamage(player2.specialAttack);

	player3.beRepaired(30);
	return 1;
}
