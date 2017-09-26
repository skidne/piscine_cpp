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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fpoint;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fpoint = raw;
}

Fixed &	Fixed::operator=(Fixed const & right)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fpoint = right.getRawBits();

	return *this;
}

const int	Fixed::_frbits = 8;
