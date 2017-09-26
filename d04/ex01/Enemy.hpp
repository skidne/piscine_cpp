#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>


class Enemy {

private:

	std::string			_type;
	int					_hp;

public:

	Enemy(int hp, std::string const & type);
	Enemy();
	Enemy(Enemy & r);
	virtual ~Enemy();

	Enemy & operator=(Enemy & r);

	std::string	const getType() const;
	int			getHP() const;
	void		setHP(int hp);
	void		setType(std::string const typ);

	virtual void takeDamage(int);

};

#endif