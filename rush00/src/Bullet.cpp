#include "Enemy.hpp"

Bullet::Bullet()
{
	this->init(PLAYER);
}

Bullet::Bullet(Bullet & bull)
{
	this->x = bull.x;
	this->y = bull.y;
	this->type = bull.type;
	this->invisible = bull.invisible;
}

Bullet::~Bullet()
{ return ; }

Bullet & Bullet::operator=(Bullet & bull)
{
	this->x = bull.x;
	this->y = bull.y;
	this->type = bull.type;
	this->invisible = bull.invisible;

	return *this;
}

void	Bullet::init(int type)
{
	this->type = type;
	this->x = -1;
	this->y = -1;
	this->invisible = true;
}

bool	Bullet::available()
{
	return this->invisible;
}

void	Bullet::shoot(int x, int y)
{
	this->x = x;
	this->y = y;
	this->invisible = false;
}

void	Bullet::draw()
{
	if (this->type == PLAYER)
		mvaddch(this->y, this->x, BULLET | COLOR_PAIR(4));
	else
		mvaddch(this->y, this->x, BULLET | COLOR_PAIR(2));
}

void	Bullet::out()
{
	this->x = -1;
	this->y = -1;
	this->invisible = true;
}

void	Bullet::move()
{
	if (type == PLAYER)
	{
		this->y--;
		if (this->y < 0)
			this->out();
	}
	else
	{
		this->y++;
		if (this->y > LINES)
			this->out();
	}
}

void	Bullet::checkCollision(Player & p)
{
	if ((x == p.x1 && y == p.y1) || (x <= p.x2 + 4 && !(x < p.x2) &&
										y == p.y2))
	{
		p.setLives(p.getLives() - 1);
		this->out();
	}
}

void	Bullet::checkCollision(Enemy (&e)[MAXNR])
{
	for (int i = 0; i < MAXNR; i++)
	{
		if (e[i].lives && ((x <= e[i].x1 + 4 && !(x < e[i].x1) && y == e[i].y1) ||
			(x <= e[i].x2 + 2 && !(x < e[i].x2) && y == e[i].y2)))
		{
			e[i].die();
			this->out();
		}
	}
}
