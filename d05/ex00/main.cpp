#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b = Bureaucrat(); // grade 150
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
    b.incrementGrade();     // grade 1
    OUT << b;
    return 0;
}