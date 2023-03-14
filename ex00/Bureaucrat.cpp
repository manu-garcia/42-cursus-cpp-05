#include "Bureaucrat.hpp"

#define DEFAULT_NAME "Un-named bureaucrat"

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

Bureaucrat::Bureaucrat() : name(DEFAULT_NAME), grade(MIN_GRADE)
{
    std::cout << getName() << ", bureaucrat Default constructor." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name), grade(grade)
{
    std::cout << getName() << ", bureaucrat constructor with params." << std::endl;

    if (grade < MAX_GRADE)
        throw GradeTooHighException();

    if (grade > MIN_GRADE)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
    *this = bureaucrat;
    std::cout << getName() << ", bureaucrat Copy constructor." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << getName() << ", bureaucrat destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    name = bureaucrat.getName();
    grade = bureaucrat.getGrade();

    std::cout << getName() << ", bureaucrat copy operator." << std::endl;

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

std::string Bureaucrat::getName(void) const
{
    return name;
}

unsigned int Bureaucrat::getGrade(void) const
{
    return grade;
}

void Bureaucrat::incrementGrade(void)
{
    if (grade == MAX_GRADE)
        throw GradeTooHighException();

    grade--;
    std::cout << getName() << ", grade incremented to " << grade << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
    if (grade == MIN_GRADE)
        throw GradeTooLowException();

    grade++;
    std::cout << getName() << ", grade decremented to " << grade << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
}
