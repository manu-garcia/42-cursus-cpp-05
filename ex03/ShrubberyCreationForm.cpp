#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define DEFAULT_FORM_NAME "ShrubberyCreationForm"
#define DEFAULT_TARGET "default target"
#define SIGN_GRADE 145
#define EXEC_GRADE 137

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(DEFAULT_FORM_NAME, false, SIGN_GRADE, EXEC_GRADE), target(DEFAULT_TARGET)
{
    std::cout << getTarget() << ", ShrubberyCreationForm Default constructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(DEFAULT_FORM_NAME, false, SIGN_GRADE, EXEC_GRADE), target(target)
{
    std::cout << getTarget() << ", form constructor with params." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)  : AForm(form.getName(), form.getIsSigned(), form.getGradeToSign(), form.getGradeToExec()), target(form.getTarget())
{
    *this = form;
    std::cout << getTarget() << ", form Copy constructor." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << getTarget() << ", form destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

std::string ShrubberyCreationForm::getTarget(void) const
{
    return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);

    std::ofstream out(target + "_shrubbery");

    out << "         # #### ####            " << std::endl;
    out << "     ### ..#|### |/####         " << std::endl;
    out << "     ##..#/ .||/##/_/##/_#      " << std::endl;
    out << "     ###  ..###|/ .. # ###      " << std::endl;
    out << " ##_._#._.## | #/###_/_####     " << std::endl;
    out << " ## #### # . #| /  #### ##/##   " << std::endl;
    out << " __#_--###`  |{,###---###-~     " << std::endl;
    out << "             . }{               " << std::endl;
    out << "             }}{                " << std::endl;
    out << "             }}{                " << std::endl;
    out << "         ejm  {{}               " << std::endl;
    out << "     , -=-~{ .-^- _             " << std::endl;

    out << std::endl;
    out.close();
}
