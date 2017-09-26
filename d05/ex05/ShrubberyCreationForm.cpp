//
// Created by Alen BADRAJAN on 7/26/17.
//

#include <string>
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : _target("zaz"), _sign(145), _exec(137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(STR const s): _target(s), _sign(145), _exec(137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &f) :_sign(145), _exec(137)
{
    set_target(f.get_target());
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &f)
{
    set_target(f.get_target());
    return *this;
}

STR ShrubberyCreationForm::get_target()const
{
    return _target;
}

void ShrubberyCreationForm::set_target(STR t)
{
    _target = t;
}


int ShrubberyCreationForm::get_sign() const
{
    return _sign;
}

int ShrubberyCreationForm::get_exec() const
{
    return _exec;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    Form::execute(executor);
    try
    {
        if (!is_isSigned() || executor.get_grade() > _exec)
            throw std::exception();
        else
            OUT << "Create a file called " <<  _target << " shrubbery, and write ASCII trees inside it, in the current directory.\n";
    }
    catch (std::exception & e)
    {
        OUT << " Error! isSiged is false or you have a low grade\n";
    }
}
