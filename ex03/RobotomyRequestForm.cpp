#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define DEFAULT_FORM_NAME "RobotomyRequestForm"
#define DEFAULT_TARGET "default target"
#define SIGN_GRADE 72
#define EXEC_GRADE 45

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm() : AForm(DEFAULT_FORM_NAME, false, SIGN_GRADE, EXEC_GRADE), target(DEFAULT_TARGET)
{
    std::cout << getTarget() << ", RobotomyRequestForm Default constructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(DEFAULT_FORM_NAME, false, SIGN_GRADE, EXEC_GRADE), target(target)
{
    std::cout << getTarget() << ", form constructor with params." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)  : AForm(form.getName(), form.getIsSigned(), form.getGradeToSign(), form.getGradeToExec()), target(form.getTarget())
{
    *this = form;
    std::cout << getTarget() << ", form Copy constructor." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << getTarget() << ", form destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

std::string RobotomyRequestForm::getTarget(void) const
{
    return target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);

	std::cout << "Making some drilling noises..." << std::endl;

    srand(time(0));
	if (rand() % 2)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << target << " robotomy failed" << std::endl;
}
