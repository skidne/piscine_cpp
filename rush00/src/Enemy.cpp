#include "Enemy.hpp"

Enemy::Enemy()
{
	this->die();
}


Enemy::Enemy(Enemy & en)
{
	this->x1 = en.x1;
	this->x2 = en.x2;
	this->y1 = en.y1;
	this->y2 = en.y2;
	this->lives = en.lives;
	this->type = en.type;
}

Enemy::~Enemy() {}

Enemy & Enemy::operator=(Enemy & en)
{
	this->x1 = en.x1;
	this->x2 = en.x2;
	this->y1 = en.y1;
	this->y2 = en.y2;
	this->lives = en.lives;
	this->type = en.type;

	return *this;
}

void	Enemy::spawn()
{
	this->lives = 1;
	if (this->type == 1)
	{
		this->x1 = rand() % COLS - 3;
		this->x2 = this->x1 + 1;
		this->y1 = 0;
		this->y2 = 1;
	}
	else
	{
		this->x1 = (this->type == 2) ? COLS - 5 : 0;
		this->x2 = this->x1 + 1;
		this->y1 = rand() % (LINES / 2);
		this->y2 = this->y1 + 1;
	}
}

void	Enemy::draw()
{
	if (this->type == 1)
	{
		attron(A_BOLD | COLOR_PAIR(2));
		mvprintw(this->y1, this->x1, ENEMY1_STR1);
		mvprintw(this->y2, this->x2, ENEMY1_STR2);
		attroff(A_BOLD | COLOR_PAIR(2));
	}
	else
	{
		attron(A_BOLD | COLOR_PAIR(2));
		mvprintw(this->y1, this->x1, ENEMY2_STR1);
		mvprintw(this->y2, this->x2, ENEMY2_STR2);
		attroff(A_BOLD | COLOR_PAIR(2));
	}
}

void	Enemy::move(int x, int y)
{
	if (this->x2 > x)
	{
		this->x1--;
		this->x2--;
	}
	else
	{
		this->x1++;
		this->x2++;
	}
	if (this->y2 > y)
	{
		this->y1--;
		this->y2--;
	}
	else
	{
		this->y1++;
		this->y2++;
	}
}

void	Enemy::checkCollision(Player & p)
{
	if (p.x2 + 2 > x1 && p.x2 + 2 < x1 + 5 && 
		(p.y1 == p.y2 || p.y1 == y2))
	{
		p.setLives(0);
		this->die();
	}
}

void	Enemy::die()
{
	this->x1 = COLS * 2;
	this->x2 = COLS * 2;
	this->y1 = LINES * 2;
	this->y2 = LINES * 2;
	this->lives = 0;
	this->type = 0;
}

void	Enemy::shoot(Bullet (&b)[MAXNR])
{
	for (int i = 0; i < MAXNR; i++)
		if (b[i].available())
		{
			b[i].shoot(this->x2 + 1, this->y2);
			return ;
		}
}

