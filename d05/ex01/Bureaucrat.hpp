//
// Created by Alen BADRAJAN on 7/26/17.
//

#ifndef EX00_BUREAUCRAT_HPP
# define EX00_BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
class Form;
# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl

class Bureaucrat
{
private:
    STR const _name;
    int       _grade; // ranges from 1 (highest possible) to 150 (lowest possible)
public:
	Bureaucrat();
    Bureaucrat(STR const n, int const gr);
    Bureaucrat(Bureaucrat const & b);
    Bureaucrat &operator=(Bureaucrat & b);

	~Bureaucrat();

    /* =============== Getters & Setters =============== */
    const std::string &get_name() const;
    int get_grade() const;
    void set_grade(int _grade);
    /* ============= END Getters & Setters ============= */

    /* - - - - - - - - - - - - - - - - - - - - - - - - - */

    /* ==================== Methods ==================== */
    void incrementGrade();
    void decrementGrade();
    void signForm(Form *f);

    void GradeTooHighException();
    void GradeTooLowException();
    /* ================== END Methods ================== */
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &r);

#endif //EX00_BUREAUCRAT_HPP
