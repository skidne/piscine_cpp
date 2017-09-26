#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>

class Fixed {

public:

	/********CONSTRUCTORS & DESTRUCTORS*********/

	Fixed();
	Fixed(Fixed const & fix);
	Fixed(int const nr);
	Fixed(float const nr);
	Fixed(double const nr);
	~Fixed();

	/********GETTERS & SETTERS*********/

	int		getRawBits() const;
	void	setRawBits(int const raw);

	/********OPERATORS**********/

	bool	operator>(Fixed const & r);
	bool	operator<(Fixed const & r);
	bool	operator>=(Fixed const & r);
	bool	operator<=(Fixed const & r);
	bool	operator==(Fixed const & r);
	bool	operator!=(Fixed const & r);

	Fixed &	operator=(Fixed const & r);
	Fixed	operator+(Fixed const & r);
	Fixed	operator-(Fixed const & r);
	Fixed	operator*(Fixed const & r);
	Fixed	operator/(Fixed const & r);

	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);

	/********OTHER*********/

	float	toFloat() const;
	int		toInt() const;

	static Fixed &			min(Fixed & a, Fixed & b);
	static Fixed const &	min(Fixed const & a, Fixed const & b);
	static Fixed &			max(Fixed & a, Fixed & b);
	static Fixed const &	max(Fixed const & a, Fixed const & b);


private:

	int					_fpoint;
	static const int	_frbits;
	
};

std::ostream &	operator<<(std::ostream & o, Fixed const & r);

#endif