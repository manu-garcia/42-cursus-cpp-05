#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Form;

class Bureaucrat
{
private:
    const std::string name;
    unsigned int grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat &bureaucrat);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &bureaucrat);

    std::string getName() const;
    unsigned int getGrade() const;
    void incrementGrade(void);
    void decrementGrade(void);
    void signForm(Form &form);

    class GradeTooHighException : public std::runtime_error
    {
    public:
        GradeTooHighException()
            : std::runtime_error("The grade is too high!") {}
    };

    class GradeTooLowException : public std::runtime_error
    {
    public:
        GradeTooLowException()
            : std::runtime_error("The grade is too low!") {}
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif