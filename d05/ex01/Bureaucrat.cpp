//
// Created by Alen BADRAJAN on 7/26/17.
//

#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat")
{
    set_grade(150);

}

Bureaucrat::Bureaucrat(STR const n, int const gr) : _name(n)
{
    set_grade(gr);
}

Bureaucrat::Bureaucrat(Bureaucrat const &b)  : _name(b.get_name())
{
    Bureaucrat::set_grade(b.get_grade());
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &b)
{
    Bureaucrat::set_grade(b.get_grade());
    return *this;
}

Bureaucrat::~Bureaucrat()
{

}

const std::string &Bureaucrat::get_name() const
{
    return _name;
}

int Bureaucrat::get_grade() const
{
    return _grade;
}

void Bureaucrat::set_grade(int _grade)
{
    Bureaucrat::_grade = _grade;
}

void Bureaucrat::incrementGrade()
{
    GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    GradeTooLowException();
}

void Bureaucrat::GradeTooHighException()
{
    try
    {
        /* do some stuff with bureaucrats */
        if (Bureaucrat::get_grade() - 1 < 1)
            throw std::exception();
        else
            set_grade(get_grade() - 1);
    }
    catch (std::exception & e)
    {
        OUT << "Grade is too high!\n";
        set_grade(1);
    }
}

void Bureaucrat::GradeTooLowException()
{
    try
    {
        /* do some stuff with bureaucrats */
        if (Bureaucrat::get_grade() + 1 > 150)
            throw std::exception();
        else
            set_grade(get_grade() + 1);
    }
    catch (std::exception & e)
    {
        OUT << "Grade is too low!\n";
        set_grade(150);
    }
}

void Bureaucrat::signForm(Form *f)
{
    if (f->beSigned(*this))
        OUT << get_name() << " signs " << f->get_name() << ENDL;
    else
        OUT << get_name() << "cannot sign " << f->get_name() << " because grade is too low\n";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &r)
{
    o << r.get_name() <<  ", bureaucrat grade " << r.get_grade() << ".\n";
    return o;
}
