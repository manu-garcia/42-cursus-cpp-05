#include "Form.hpp"
#include "Bureaucrat.hpp"

#define DEFAULT_NAME "Un-named form"
#define MIN_GRADE 150
#define MAX_GRADE 1

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

Form::Form() : name(DEFAULT_NAME), isSigned(false), gradeToSign(MIN_GRADE), gradeToExec(MIN_GRADE)
{
    std::cout << getName() << ", form Default constructor." << std::endl;
}

Form::Form(std::string name, bool isSigned, unsigned int gradeToSign, unsigned int gradeToExec) : name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
    std::cout << getName() << ", form constructor with params." << std::endl;

    if (gradeToSign < MAX_GRADE || gradeToExec < MAX_GRADE)
        throw GradeTooHighException();

    if (gradeToSign > MIN_GRADE || gradeToExec > MIN_GRADE)
        throw GradeTooLowException();
}

Form::Form(const Form &form)
{
    *this = form;
    std::cout << getName() << ", form Copy constructor." << std::endl;
}

Form::~Form()
{
    std::cout << getName() << ", form destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

Form &Form::operator=(const Form &form)
{
    name = form.getName();
    isSigned = form.getIsSigned();
    gradeToSign = form.getGradeToSign();
    gradeToExec = form.getGradeToExec();

    std::cout << getName() << ", form copy operator." << std::endl;

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

std::string Form::getName(void) const
{
    return name;
}

bool Form::getIsSigned(void) const
{
    return isSigned;
}

unsigned int Form::getGradeToSign(void) const
{
    return gradeToSign;
}

unsigned int Form::getGradeToExec(void) const
{
    return gradeToExec;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    std::cout << getName() << ", form is trying to be signed by " << bureaucrat.getName() << std::endl;

    if (bureaucrat.getGrade() > gradeToSign)
    {
        throw GradeTooLowException();
    }
    
    isSigned = true;
    std::cout << "Signed!!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    return os << form.getName() << ", form signed " << form.getIsSigned() <<
            ", grade to sign " << form.getGradeToSign() <<
            ", grade to exec " << form.getGradeToExec() << "." << std::endl;
}
