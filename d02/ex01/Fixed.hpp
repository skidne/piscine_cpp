#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {

public:

	Fixed();
	Fixed(Fixed const & fix);
	Fixed(int const nr);
	Fixed(float const nr);
	~Fixed();

	Fixed &	operator=(Fixed const & right);
	int		getRawBits() const;
	void	setRawBits(int const raw);

	float toFloat() const;
	int toInt() const;


private:

	int					_fpoint;
	static const int	_frbits;
	
};

std::ostream &	operator<<(std::ostream & o, Fixed const & r);

#endif