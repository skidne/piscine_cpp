//
// Created by Alen BADRAJAN on 7/27/17.
//

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Form *Intern::makeForm(STR const nm, STR const target)
{
    try
    {
        Form *rb;

        if (nm == "robotomy request")
        {
            RobotomyRequestForm *r =  new RobotomyRequestForm(target);
            rb = (Form *) r;
            OUT << "Intern creates " << target << ENDL;
            return (rb);
        } else if (nm == "shurbbery request")
        {
            ShrubberyCreationForm *s =  new ShrubberyCreationForm(target);
            rb = (Form *) s;
            OUT << "Intern creates " << target << ENDL;
            return (rb);
        } else if (nm == "presidential request")
        {
            PresidentialPardonForm *p =  new PresidentialPardonForm(target);
            rb = (Form *) p;
            OUT << "Intern creates " << target << ENDL;
            return (rb);
        } else
            throw std::exception();

    }
    catch (std::exception & e)
    {
        OUT << "Just don't mess something up! How did you got this job?\n";
        throw e;
    }
    return NULL;
}
