#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define DEFAULT_FORM_NAME "PresidentialPardonForm"
#define DEFAULT_TARGET "default target"
#define SIGN_GRADE 25
#define EXEC_GRADE 5

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm() : AForm(DEFAULT_FORM_NAME, false, SIGN_GRADE, EXEC_GRADE), target(DEFAULT_TARGET)
{
    std::cout << getTarget() << ", PresidentialPardonForm Default constructor." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(DEFAULT_FORM_NAME, false, SIGN_GRADE, EXEC_GRADE), target(target)
{
    std::cout << getTarget() << ", form constructor with params." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)  : AForm(form.getName(), form.getIsSigned(), form.getGradeToSign(), form.getGradeToExec()), target(form.getTarget())
{
    *this = form;
    std::cout << getTarget() << ", form Copy constructor." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << getTarget() << ", form destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

std::string PresidentialPardonForm::getTarget(void) const
{
    return target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);

    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
