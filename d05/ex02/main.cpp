#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat  b = Bureaucrat(); // grade 150
    Form        f = Form("kek", 10, 1);
    Form        f2 = Form("ke2k", 1, 1);

    ShrubberyCreationForm sh = ShrubberyCreationForm();
    RobotomyRequestForm rb = RobotomyRequestForm();
    PresidentialPardonForm pr = PresidentialPardonForm();

    OUT << b;
    b.incrementGrade();     // grade 149
    OUT << b;
    b.decrementGrade();     // grade 150
    OUT << b;
    b.decrementGrade();     // grade 150
    OUT << b;
    b.decrementGrade();     // grade 150

    OUT << b;
    b.set_grade(5);
    b.incrementGrade();     // grade 4
    OUT << b;
    b.incrementGrade();     // grade 3
    OUT << b;
    b.incrementGrade();     // grade 2
    OUT << b;
    b.incrementGrade();     // grade 1
    OUT << b;
    OUT << ENDL;
    b.incrementGrade();     // grade 1
    b.set_grade(6);         // grade 6
    OUT << b;
    f.beSigned(b);
    OUT << f;
    OUT << f.beSigned(b) << ENDL;
    OUT << f2.beSigned(b) << ENDL;

    b.signForm(&f);
    b.signForm((Form *) &sh);
    b.signForm(&f2);

//    f.execute(b);
    sh.execute(b);
    rb.execute(b);
    pr.execute(b);

    b.signForm((Form *) &rb);

    rb.execute(b);
    pr.execute(b);

    b.executeForm(f);
    b.executeForm(f2);
    return 0;
}