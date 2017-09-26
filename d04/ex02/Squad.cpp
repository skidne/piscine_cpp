//
// Created by Alen BADRAJAN on 7/25/17.
//

#include "Squad.hpp"

int     Squad::nr_atributes = 0;

Squad::Squad()
{
    this->s = new ISpaceMarine*[Squad::nr_atributes];
}

Squad::Squad(Squad &f)
{
	*this = f;
}

Squad::~Squad()
{
	if (this->getCount())
		for (int i = 0; i < this->getCount(); i++)
			delete this->s[i];
}

Squad &Squad::operator=(Squad &r)
{
	if (this->getCount())
		for (int i = 0; i < this->getCount(); i++)
			delete this->s[i];
	this->s = r.s;
	Squad::nr_atributes = r.getCount();

	return *this;
}

int Squad::getCount() const
{
    return Squad::nr_atributes;
}

ISpaceMarine * Squad::getUnit(int n) const
{
	int		i = 0;

	while (i < this->getCount() && i != n)
		i++;
	if (i == n)
		return s[i];
	return NULL;
}

int Squad::push(ISpaceMarine *w)
{
	int i = 0;

	while (i < this->getCount())
		if (this->s[i++] == w)
			return this->getCount();

	ISpaceMarine **n = new ISpaceMarine*[Squad::nr_atributes + 1];
	for (int i = 0; i < Squad::nr_atributes; i++)
		n[i] = this->s[i];
	n[Squad::nr_atributes] = w;
	delete [] this->s;
	this->s = n;
	Squad::nr_atributes++;
	return this->getCount();
}
