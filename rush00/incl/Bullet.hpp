#ifndef BULLET_H
# define BULLET_H

#include "header.hpp"

class Player;
class Enemy;

class Bullet {

public:

	Bullet();
	Bullet(Bullet & bull);
	~Bullet();

	Bullet & operator=(Bullet & bull);

	int		type;
	int		x;
	int		y;
	bool	invisible;

	void	init(int type);
	bool	available();
	void	checkCollision(Player & player);
	void	checkCollision(Enemy (&e)[MAXNR]);
	void	shoot(int x, int y);
	void	draw();
	void	out();
	void	move();

};

#endif