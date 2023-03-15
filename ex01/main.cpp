#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
        Form form("Signeable form", false, 1, 1);

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
        Bureaucrat bureaucrat("Bad signer bureaucrat", 2);
        Form form("Un-signeable form", false, 1, 1);

        bureaucrat.signForm(form);
    }
    catch (std::exception &e)
    {
    }

    return 0;
}