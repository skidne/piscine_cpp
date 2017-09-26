#ifndef ENEMY_H
# define ENEMY_H

#include "Player.hpp"

class Enemy {

public:

	Enemy();
	Enemy(Enemy & en);
	~Enemy();
	
	Enemy & operator=(Enemy & r);

	void	spawn();
	void	draw();
	void	move(int x, int y);
	void	die();
	void	checkCollision(Player & p);
	void	shoot(Bullet (&bullets)[MAXNR]);

	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		lives;
	int		type;

};

#endif