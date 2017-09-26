//
// Created by Alen BADRAJAN on 7/26/17.
//

#ifndef EX02_ROBOTOMYREQUESTFORM_HPP
#define EX02_ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : Form
{
private:
    STR          _target;
    int const    _sign;
    int const    _exec;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(STR const s);
    RobotomyRequestForm(RobotomyRequestForm const & f);
    RobotomyRequestForm &operator=(RobotomyRequestForm & f);

    /* =============== Getters & Setters =============== */
    STR     get_target()const;
    void    set_target(STR t);
    void    execute(Bureaucrat const & executor) const;
    int get_sign() const;
    int get_exec() const;
    /* ============= END Getters & Setters ============= */

};

#endif //EX02_ROBOTOMYREQUESTFORM_HPP
