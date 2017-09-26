#include "Player.hpp"

Player::Player()
{
	this->init(1);
}

Player::Player(Player & pl)
{
	this->setLives(pl.getLives());
	this->setScore(pl.getScore());
	this->x1 = pl.x1;
	this->x2 = pl.x2;
	this->y1 = pl.y1;
	this->y2 = pl.y2;
}

Player::~Player()
{ return ; }

Player &	Player::operator=(Player & r)
{
	this->speed = r.speed;
	this->setLives(r.getLives());
	this->setScore(r.getScore());
	this->x1 = r.x1;
	this->x2 = r.x2;
	this->y1 = r.y1;
	this->y2 = r.y2;

	return *this;
}

void	Player::init(int speed)
{
	this->speed = speed;
	this->x1 = COLS / 2 - 1;
	this->x2 = COLS / 2 - 3;
	this->y1 = LINES - 2;
	this->y2 = LINES - 1;
	this->_lives = 3;
	this->_score = 0;
}

int		Player::getLives()
{
	return this->_lives;
}

int		Player::getScore()
{
	return this->_score;
}

void	Player::setLives(int lives)
{
	this->_lives = lives;
}

void	Player::setScore(int score)
{
	this->_score = score;
}

void	Player::draw()
{
	attron(A_BOLD | COLOR_PAIR(4));
	mvprintw(this->y1, this->x1, PLAYER_STR1);
	mvprintw(this->y2, this->x2, PLAYER_STR2);
	attroff(A_BOLD | COLOR_PAIR(4));
}

void	Player::move(int dir)
{
	if (dir == RIGHT && this->x2 + 6 <= COLS)
	{
		this->x1 += this->speed;
		this->x2 += this->speed;
	}
	else if (dir == LEFT && this->x2 > 1)
	{
		this->x1 -= this->speed;
		this->x2 -= this->speed;
	}
	else if (dir == UP && this->y1 > 2)
	{
		this->y1 -= this->speed;
		this->y2 -= this->speed;
	}
	else if (dir == DOWN && this->y2 + 1 < LINES)
	{
		this->y1 += this->speed;
		this->y2 += this->speed;
	}
}

void	Player::shoot(Bullet (&bullet)[MAXNR])
{
	for (int i = 0; i < MAXNR; i++)
		if (bullet[i].available())
		{
			bullet[i].shoot(this->x1, this->y1);
			return ;
		}
}
