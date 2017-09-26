#include "Fixed.hpp"

Fixed::Fixed() : _fpoint(0)
{ return ; }

Fixed::Fixed(Fixed const & fix)
{
	*this = fix;
	return ;
}

Fixed::Fixed(int const nr)
{
	this->_fpoint = nr << this->_frbits;
	return ;
}

Fixed::Fixed(float const nr)
{
	this->_fpoint = roundf(nr * (1 << this->_frbits));
	return ;
}

Fixed::~Fixed()
{ return ; }

int		Fixed::getRawBits(void) const
{
	return this->_fpoint;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fpoint = raw;
}

bool	Fixed::operator>(Fixed const & r)
{
	return this->_fpoint > r.getRawBits();
}

bool	Fixed::operator<(Fixed const & r)
{
	return this->_fpoint < r.getRawBits();
}

bool	Fixed::operator>=(Fixed const & r)
{
	return this->_fpoint >= r.getRawBits();
}

bool	Fixed::operator<=(Fixed const & r)
{
	return this->_fpoint <= r.getRawBits();
}

bool	Fixed::operator==(Fixed const & r)
{
	return this->_fpoint == r.getRawBits();
}

bool	Fixed::operator!=(Fixed const & r)
{
	return this->_fpoint != r.getRawBits();
}

Fixed &	Fixed::operator=(Fixed const & right)
{
	this->_fpoint = right.getRawBits();

	return *this;
}

Fixed	Fixed::operator+(Fixed const & r)
{
	Fixed	fix;

	fix.setRawBits(this->_fpoint + r.getRawBits());
	return fix;
}

Fixed	Fixed::operator-(Fixed const & r)
{
	Fixed	fix;

	fix.setRawBits(this->_fpoint - r.getRawBits());
	return fix;
}

Fixed	Fixed::operator*(Fixed const & r)
{
	Fixed	fix;

	fix.setRawBits( (this->_fpoint * r.getRawBits()) >> this->_frbits );
	return fix;
}

Fixed	Fixed::operator/(Fixed const & r)
{
	Fixed	fix;

	fix.setRawBits( (this->_fpoint << this->_frbits) / r.getRawBits() );
	return fix;
}

Fixed	Fixed::operator++()
{
	this->_fpoint++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	f;

	f = *this;
	this->_fpoint++;
	return f;
}

Fixed	Fixed::operator--()
{
	this->_fpoint--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	f;

	f = *this;
	this->_fpoint--;
	return f;
}

float	Fixed::toFloat() const
{
	return (float)(this->_fpoint) / (1 << this->_frbits);
}

int		Fixed::toInt() const
{
	return this->_fpoint >> this->_frbits;
}

Fixed &			Fixed::min(Fixed & a, Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed &			Fixed::max(Fixed & a, Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & r)
{
	o << r.toFloat();
	return o;
}

const int	Fixed::_frbits = 8;
