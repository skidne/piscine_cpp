//
// Created by Alen BADRAJAN on 7/27/17.
//

#ifndef EX03_INTERN_HPP
# define EX03_INTERN_HPP

#include <iostream>
#include <stdexcept>

#include "Form.hpp"

# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl

class Intern
{
public:
	Intern();
    ~Intern();

     Form* makeForm(STR const nm, STR const target);
};

#endif //EX03_INTERN_HPP
