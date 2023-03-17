#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#define INTERN_SHRUBERRY_FORM "shrubbery creation"
#define INTERN_ROBOTOMY_FORM "robotomy request"
#define INTERN_PRESIDENTIAL_FORM "presidential pardon"

class AForm;

class Intern
{

public:
    Intern();
    Intern(const Intern &intern);
    ~Intern();

    Intern &operator=(const Intern &intern);

    AForm* ShrubberyCreationFormFactory(std::string target);
    AForm* RobotomyRequestFormFactory(std::string target);
    AForm* PresidentialPardonFormFactory(std::string target);

    AForm* makeForm(std::string formName, std::string target);

};

#endif