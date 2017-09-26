#include "Form.hpp"

Form::Form() : _name("From"), _grade_signIn(100), _grade_execute(50)
{
    set_isSigned(false);
}

Form::Form(Form const &f) : _name(f.get_name()), _grade_signIn(f.get_grade_signIn()), _grade_execute(f.get_grade_execute())
{
    GradeTooLowException();
    GradeTooHighException();
    set_isSigned(false);
}

Form::Form(STR const n, int const grIn, int const grEx) : _name(n), _grade_signIn(grIn), _grade_execute(grEx)
{
    GradeTooLowException();
    GradeTooHighException();
    set_isSigned(false);
}

Form &Form::operator=(Form &f)    //only isSigned
{
    Form::set_isSigned(f.is_isSigned());
    return *this;
}

const std::string &Form::get_name() const
{
    return _name;
}

bool Form::is_isSigned() const
{
    return _isSigned;
}

void Form::set_isSigned(bool _isSigned)
{
    Form::_isSigned = _isSigned;
}

int Form::get_grade_signIn() const
{
    return _grade_signIn;
}

int Form::get_grade_execute() const
{
    return _grade_execute;
}

void Form::GradeTooHighException()
{
    try
    {
        /* do some stuff with Forms */
        if (Form::get_grade_signIn() < 1 || Form::get_grade_execute() < 1)
            throw std::exception();
        else
            OUT << "Grade/s  are not too high\n";
    }
    catch (std::exception & e)
    {
        OUT << "===\nGrade/s are too high!\nPlease reconstruct them!\n===\n";
    }
}

void Form::GradeTooLowException()
{
    try
    {
        /* do some stuff with Forms */
        if (Form::get_grade_signIn() > 150 || Form::get_grade_execute() > 150)
            throw std::exception();
        else
            OUT << "Grade/s  are not too low\n";
    }
    catch (std::exception & e)
    {
        OUT << "===\nGrade/s are too low!\nPlease reconstruct them!\n===\n";
    }
}

bool Form::beSigned(Bureaucrat b)
{
    if (b.get_grade() <= get_grade_signIn())
    {
        set_isSigned(true);
        return true;
    }
    return false;
}

void Form::execute(Bureaucrat const &executor) const
{
    if (!is_isSigned() || executor.get_grade() < _grade_execute)
        OUT << "OOps, something is wrong!\n";
}

std::ostream &operator<<(std::ostream &o, Form const &r)
{
    o << r.get_name() <<  " is a form with grIn =" << r.get_grade_signIn() << ", and grEx = " << r.get_grade_execute() << ".\n";
    return o;
}

