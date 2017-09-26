#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat  b = Bureaucrat(); // grade 150
    Form        f = Form("kek", 10, 1);
    Form        f2 = Form("kek", 3, 1);
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
    b.signForm(&f2);
    return 0;
}