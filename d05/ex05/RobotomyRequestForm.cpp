//
// Created by Alen BADRAJAN on 7/26/17.
//

#include <string>
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : _target("zaz"), _sign(72), _exec(45)
{
}

RobotomyRequestForm::RobotomyRequestForm(STR const s): _target(s), _sign(72), _exec(45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &f) : _sign(72), _exec(45)
{
    set_target(f.get_target());
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &f)
{
    set_target(f.get_target());
    return *this;
}


STR RobotomyRequestForm::get_target()const
{
    return _target;
}

void RobotomyRequestForm::set_target(STR t)
{
    _target = t;
}


int RobotomyRequestForm::get_sign() const
{
    return _sign;
}

int RobotomyRequestForm::get_exec() const
{
    return _exec;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    Form::execute(executor);
    try
    {
        if (!is_isSigned() || executor.get_grade() > _exec)
            throw std::exception();
        else
            OUT << "Makes some drilling noises, and tells us that " << _target << " has been robotomized successfully 50% of the time. the rest of times, tells us it’s a failure.\n";
    }
    catch (std::exception & e)
    {
        OUT << " Error! isSiged is false or you have a low grade\n";
    }
}
