#ifndef PONY_H
# define PONY_H

#include <iostream>
#include <string>

class Pony {

public:

	Pony(int hp, int mana);
	~Pony();

	int	getHP(void);
	int	getMana(void);
	
private:

	int	_hp;
	int	_mana;

};

#endif