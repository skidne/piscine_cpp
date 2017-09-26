//
// Created by Alen BADRAJAN on 7/26/17.
//

#ifndef EX02_PRESIDENTIALPARDONFORM_HPP
#define EX02_PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : Form
{
private:
    STR          _target;
    int const    _sign;
    int const    _exec;
public:
	PresidentialPardonForm();
    PresidentialPardonForm(STR const s);
    PresidentialPardonForm(PresidentialPardonForm const & f);
    PresidentialPardonForm &operator=(PresidentialPardonForm & f);

    /* =============== Getters & Setters =============== */
    STR     get_target()const;
    void    set_target(STR t);
    void    execute(Bureaucrat const & executor) const;
    int get_sign() const;
    int get_exec() const;
    /* ============= END Getters & Setters ============= */

};

#endif //EX02_PRESIDENTIALPARDONFORM_HPP
