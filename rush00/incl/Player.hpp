#ifndef PLAYER_H
# define PLAYER_H

#include "Bullet.hpp"

class Enemy;

class Player {

public:

/******* CONSTRUCTORS *********/

	Player();
	Player(Player & pl);
	~Player();

	Player & operator=(Player & r);

/******** GETTERS & SETTERS *********/

	int		getLives();
	int		getScore();

	void	setLives(int smth);
	void	setScore(int smth);

/******** OTHER **********/ 

	void	init(int speed);
	void	draw();
	void	move(int direction);
	void	shoot(Bullet (&bullets)[MAXNR]);

	int		speed;
	int		x1;
	int		x2;
	int		y1;
	int		y2;

private:

	int		_lives;
	int		_score;
	
};

#endif