#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define DEFAULT_NAME "Un-named form"
#define MIN_GRADE 150
#define MAX_GRADE 1

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

AForm::AForm() : name(DEFAULT_NAME), isSigned(false), gradeToSign(MIN_GRADE), gradeToExec(MIN_GRADE)
{
    std::cout << getName() << ", form Default constructor." << std::endl;
}

AForm::AForm(std::string name, bool isSigned, unsigned int gradeToSign, unsigned int gradeToExec) : name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    std::cout << getName() << ", form constructor with params." << std::endl;

    if (gradeToSign < MAX_GRADE || gradeToExec < MAX_GRADE)
        throw GradeTooHighException();

    if (gradeToSign > MIN_GRADE || gradeToExec > MIN_GRADE)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &form) : name(form.getName()), gradeToSign(form.getGradeToSign()), gradeToExec(form.getGradeToExec())
{
    *this = form;
    std::cout << getName() << ", form Copy constructor." << std::endl;
}

AForm::~AForm()
{
    std::cout << getName() << ", form destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

AForm &AForm::operator=(const AForm &form)
{
    isSigned = form.getIsSigned();

    std::cout << getName() << ", form copy operator." << std::endl;

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

std::string AForm::getName(void) const
{
    return name;
}

bool AForm::getIsSigned(void) const
{
    return isSigned;
}

unsigned int AForm::getGradeToSign(void) const
{
    return gradeToSign;
}

unsigned int AForm::getGradeToExec(void) const
{
    return gradeToExec;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    std::cout << getName() << ", form is trying to be signed by " << bureaucrat.getName() << std::endl;

    if (bureaucrat.getGrade() > gradeToSign)
    {
        throw GradeTooLowException();
    }

    isSigned = true;
    std::cout << "Signed!!" << std::endl;
}

void AForm::execute(Bureaucrat const & executor) const
{
    std::cout << getName() << ", " << getName() << " is trying to be executed by " << executor.getName() << std::endl;

    if (executor.getGrade() > getGradeToExec())
    {
        throw GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    return os << form.getName() << ", form signed " << form.getIsSigned() << ", grade to sign " << form.getGradeToSign() << ", grade to exec " << form.getGradeToExec() << "." << std::endl;
}
