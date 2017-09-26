//
// Created by Alen BADRAJAN on 7/27/17.
//

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : intern(Intern()), Signer(Bureaucrat()), Executor(Bureaucrat())
{

}

OfficeBlock::OfficeBlock(Intern const &i, Bureaucrat const &s, Bureaucrat const &e) : intern(i), Signer(s), Executor(e)
{

}

OfficeBlock::~OfficeBlock()
{

}


OfficeBlock &OfficeBlock::operator=(OfficeBlock &b)
{
    this->setIntern(b.intern);
    this->setSigner(b.Signer);
    this->setExecutor(b.Executor);
    return *this;
}




void OfficeBlock::doBureaucracy(STR formName, STR targetName)
{
    Form *f;

    try
    {
        f = intern.makeForm(formName, targetName);
        Signer.signForm(f);
        Executor.executeForm(*f);
    }
    catch (std::exception & e)
    {
        OUT << "Somesing is mising\n";
    }
}



/* =============== Getters & Setters =============== */
const Intern &OfficeBlock::getIntern() const
{
    return intern;
}

void OfficeBlock::setIntern(const Intern &intern) {
    OfficeBlock::intern = intern;
}

const Bureaucrat &OfficeBlock::getSigner() const {
    return Signer;
}

void OfficeBlock::setSigner(const Bureaucrat &Signer)
{
    this->Signer.set_grade(Signer.get_grade());

//    this->Signer = Signer;
}

const Bureaucrat &OfficeBlock::getExecutor() const {
    return Executor;
}

void OfficeBlock::setExecutor(const Bureaucrat &Executor)
{
    this->Executor.set_grade(Executor.get_grade());
//    OfficeBlock::Executor = Executor;
}
/* ============= END Getters & Setters ============= */
