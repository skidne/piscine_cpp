//
// Created by Alen BADRAJAN on 7/27/17.
//

#ifndef EX04_OFFICEBLOCK_HPP
# define EX04_OFFICEBLOCK_HPP

#include "Bureaucrat.hpp"
#include "Intern.hpp"

class OfficeBlock
{
private:
    Intern      intern;
    Bureaucrat  Signer;
    Bureaucrat  Executor;
public:
    OfficeBlock();
    OfficeBlock(Intern const & i, Bureaucrat const & s, Bureaucrat const & e);
    ~OfficeBlock();

    void doBureaucracy(STR formName, STR targetName);

    OfficeBlock &operator=(OfficeBlock & b);

    /* =============== Getters & Setters =============== */
    const Bureaucrat &getSigner() const;
    void setSigner(const Bureaucrat &Signer);
    const Bureaucrat &getExecutor() const;
    void setExecutor(const Bureaucrat &Executor);
    const Intern &getIntern() const;
    void setIntern(const Intern &intern);
    /* ============= END Getters & Setters ============= */

};

#endif //EX04_OFFICEBLOCK_HPP
