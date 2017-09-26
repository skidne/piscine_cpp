#include "Fixed.hpp"

Fixed::Fixed() : _fpoint(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
	return ;
}

Fixed::Fixed(int const nr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fpoint = nr << this->_frbits;
	return ;
}

Fixed::Fixed(float const nr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fpoint = roundf(nr * (1 << this->_frbits));
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const
{
	return this->_fpoint;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fpoint = raw;
}

Fixed &	Fixed::operator=(Fixed const & right)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fpoint = right.getRawBits();

	return *this;
}

float	Fixed::toFloat() const
{
	return (float)(this->_fpoint) / (1 << this->_frbits);
}

int		Fixed::toInt() const
{
	return this->_fpoint >> this->_frbits;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & r)
{
	o << r.toFloat();
	return o;
}

const int	Fixed::_frbits = 8;
