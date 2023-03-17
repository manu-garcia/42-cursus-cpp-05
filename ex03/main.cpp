#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testInternMakingForm(std::string formName, std::string target)
{
	Intern	intern;
	AForm	*form;
	form = intern.makeForm(formName, target);
    if (form) {
        delete form;
        form = NULL;   
    }
}

int main(void)
{
    try
    {
        std::cout << "Default constructor. Testing no faulty behaviour. No exception will raise!" << std::endl;
        Bureaucrat bureaucrat;

        std::cout << bureaucrat;

        bureaucrat.incrementGrade();
        bureaucrat.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Non Default Constructor. Testing no faulty behaviour. No exception will raise!" << std::endl;
        Bureaucrat bureaucrat("Good grades bureaucrat", 1);

        std::cout << bureaucrat;

        bureaucrat.decrementGrade();
        bureaucrat.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Non Default Constructor. Expecting too high exception while constructing!" << std::endl;
        Bureaucrat bureaucrat("Bad grades bureaucrat", MAX_GRADE - 1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Non Default Constructor. Expecting too low exception while constructing!" << std::endl;
        Bureaucrat bureaucrat("Bad grades bureaucrat", MIN_GRADE + 1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Non Default Constructor. Expecting too high exception!" << std::endl;
        Bureaucrat bureaucrat("Bad grades bureaucrat", 1);

        std::cout << bureaucrat;

        bureaucrat.decrementGrade();
        bureaucrat.incrementGrade();
        bureaucrat.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Default constructor, expecting too low exception!" << std::endl;
        Bureaucrat bureaucrat;

        std::cout << bureaucrat;

        bureaucrat.decrementGrade();
        bureaucrat.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "Signing forms" << std::endl;
    std::cout << std::endl;

    try
    {
        std::cout << "Expecting bureaucrat to be able to sign a form!" << std::endl;
        Bureaucrat bureaucrat("Good signer bureaucrat", 1);
        ShrubberyCreationForm form("ShrubberyCreationForm target");

        std::cout << bureaucrat;
        std::cout << form;

        bureaucrat.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Expecting bureaucrat unable to sign a form!" << std::endl;
        Bureaucrat bureaucrat("Bad signer bureaucrat", MIN_GRADE);
        ShrubberyCreationForm form("ShrubberyCreationForm target");

        bureaucrat.signForm(form);
    }
    catch (std::exception &e)
    {
    }

    std::cout << std::endl << "Executing forms" << std::endl;
    std::cout << std::endl;

    try
    {
        std::cout << "Expecting bureaucrat to be able to execute a form!" << std::endl;
        Bureaucrat bureaucrat("Good executor bureaucrat", 1);
        ShrubberyCreationForm form("ShrubberyCreationForm target");

        std::cout << bureaucrat;
        std::cout << form;

        bureaucrat.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Expecting bureaucrat unable to execute a form!" << std::endl;
        Bureaucrat bureaucrat("Bad executor bureaucrat", MIN_GRADE);
        ShrubberyCreationForm form("ShrubberyCreationForm target");

        std::cout << bureaucrat;
        std::cout << form;

        bureaucrat.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "Executing Robotomy forms" << std::endl;
    std::cout << std::endl;

    try
    {
        std::cout << "Expecting bureaucrat to be able to execute a form!" << std::endl;
        Bureaucrat bureaucrat("Good executor bureaucrat", 1);
        RobotomyRequestForm form("RobotomyRequestForm target");

        std::cout << bureaucrat;
        std::cout << form;

        bureaucrat.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Expecting bureaucrat unable to execute a form!" << std::endl;
        Bureaucrat bureaucrat("Bad executor bureaucrat", MIN_GRADE);
        RobotomyRequestForm form("RobotomyRequestForm target");

        std::cout << bureaucrat;
        std::cout << form;

        bureaucrat.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "Executing PresidentialPardon forms" << std::endl;
    std::cout << std::endl;

    try
    {
        std::cout << "Expecting bureaucrat to be able to execute a form!" << std::endl;
        Bureaucrat bureaucrat("Good executor bureaucrat", 1);
        PresidentialPardonForm form("PresidentialPardonForm target");

        std::cout << bureaucrat;
        std::cout << form;

        bureaucrat.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "Expecting bureaucrat unable to execute a form!" << std::endl;
        Bureaucrat bureaucrat("Bad executor bureaucrat", MIN_GRADE);
        PresidentialPardonForm form("PresidentialPardonForm target");

        std::cout << bureaucrat;
        std::cout << form;

        bureaucrat.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "Testing Interns making forms" << std::endl;
    std::cout << std::endl;

    testInternMakingForm("MadeUpForm", "target");
    std::cout << std::endl;

    testInternMakingForm(INTERN_SHRUBERRY_FORM, "target");
    std::cout << std::endl;
    testInternMakingForm(INTERN_ROBOTOMY_FORM, "target");
    std::cout << std::endl;
    testInternMakingForm(INTERN_PRESIDENTIAL_FORM, "target");
    std::cout << std::endl;

    return 0;
}