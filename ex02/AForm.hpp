#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool isSigned;
    const unsigned int gradeToSign;
    const unsigned int gradeToExec;

public:
    AForm();
    AForm(std::string name, bool isSigned, unsigned int gradeToSign, unsigned int gradeToExec);
    AForm(const AForm &form);
    ~AForm();

    AForm &operator=(const AForm &form);

    std::string getName() const;
    bool getIsSigned() const;
    unsigned int getGradeToSign() const;
    unsigned int getGradeToExec() const;

    void beSigned(const Bureaucrat &bureaucrat);
    void execute(Bureaucrat const & executor) const;

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

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif