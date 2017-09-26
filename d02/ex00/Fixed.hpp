#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {

public:

	Fixed();
	Fixed(Fixed const & fix);
	~Fixed();

	Fixed &	operator=(Fixed const & right);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:

	int					_fpoint;
	static const int	_frbits;
	
};

#endif