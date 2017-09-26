//
// Created by Alen BADRAJAN on 7/26/17.
//

#ifndef EX02_SHRUBBERYCREATIONFORM_HPP
#define EX02_SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : Form
{
private:
    STR          _target;
    int const    _sign;
    int const    _exec;
public:
	ShrubberyCreationForm();
    ShrubberyCreationForm(STR const s);
    ShrubberyCreationForm(ShrubberyCreationForm const & f);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm & f);

    /* =============== Getters & Setters =============== */
    STR     get_target()const;
    void    set_target(STR t);
    void    execute(Bureaucrat const & executor) const;
    int get_sign() const;
    int get_exec() const;
    /* ============= END Getters & Setters ============= */

};

#endif //EX02_SHRUBBERYCREATIONFORM_HPP
