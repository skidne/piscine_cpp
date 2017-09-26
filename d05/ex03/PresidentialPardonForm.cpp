//
// Created by Alen BADRAJAN on 7/26/17.
//

#include <string>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("zaz"), _sign(25), _exec(5)
{
}

PresidentialPardonForm::PresidentialPardonForm(STR const s): _target(s), _sign(25), _exec(5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &f) : _sign(25), _exec(5)
{
    set_target(f.get_target());
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &f)
{
    set_target(f.get_target());
    return *this;
}

STR PresidentialPardonForm::get_target()const
{
    return _target;
}

void PresidentialPardonForm::set_target(STR t)
{
    _target = t;
}

 int PresidentialPardonForm::get_sign() const
{
    return _sign;
}

 int PresidentialPardonForm::get_exec() const
{
    return _exec;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    Form::execute(executor);
    try
    {
        if (!is_isSigned() || executor.get_grade() > _exec)
            throw std::exception();
        else
            OUT << "Tells us " << _target << " has been pardoned by Zafod Beeblebrox.\n";
    }
    catch (std::exception & e)
    {
        OUT << " Error! isSiged is false or you have a low grade\n";
    }
}
