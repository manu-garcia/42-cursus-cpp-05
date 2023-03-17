#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef AForm* (Intern::*t_fn_aform_factory)(std::string);

typedef struct s_form_factory {
    std::string formName;
    t_fn_aform_factory constructor;
} t_form_factory;

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

Intern::Intern()
{
    std::cout << "Intern form Default constructor." << std::endl;
}

Intern::Intern(const Intern &form)
{
    *this = form;
    std::cout << "Intern form Copy constructor." << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern form destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

Intern &Intern::operator=(const Intern &form)
{
    (void) form;
    std::cout << "Intern form copy operator." << std::endl;

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

AForm* Intern::ShrubberyCreationFormFactory(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::RobotomyRequestFormFactory(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::PresidentialPardonFormFactory(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::cout << "Intern making form " << formName << " with target " << target << "." << std::endl;
    
    t_form_factory factories[3] = {
        { INTERN_SHRUBERRY_FORM, &Intern::ShrubberyCreationFormFactory },
        { INTERN_ROBOTOMY_FORM, &Intern::RobotomyRequestFormFactory },
        { INTERN_PRESIDENTIAL_FORM, &Intern::PresidentialPardonFormFactory },
    };

    for (int i=0; i < 3; i++)
    {
        if (factories[i].formName == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*(factories[i].constructor))(target);
        }
    }

    std::cout << "Intern could not find form " << formName << " to make!" << std::endl;
    return NULL;
}

