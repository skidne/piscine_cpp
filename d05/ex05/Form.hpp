//
// Created by Alen BADRAJAN on 7/26/17.
//

#ifndef EX01_FORM_HPP
# define EX01_FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
    STR const           _name;
    bool                _isSigned;
    int const           _grade_signIn;
    int const           _grade_execute;
public:
	Form();
    Form(STR const n, int const grIn, int const grEx);
    Form(Form const & f);
    Form &operator=(Form & f);

    /* =============== Getters & Setters =============== */
    void set_isSigned(bool _isSigned);
    const std::string &get_name() const;
    bool is_isSigned() const;
	int get_grade_signIn() const;
	int get_grade_execute() const;
	/* ============= END Getters & Setters ============= */

	/* - - - - - - - - - - - - - - - - - - - - - - - - - */

	/* ==================== Methods ==================== */
    bool beSigned(Bureaucrat b);
	virtual void execute(Bureaucrat const & executor) const;

    void GradeTooHighException();
    void GradeTooLowException();
	/* ================== END Methods ================== */
};

std::ostream &operator<<(std::ostream &o, Form const &r);

#endif //EX01_FORM_HPP
