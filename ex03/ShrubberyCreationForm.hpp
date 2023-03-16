#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &form);
    ~ShrubberyCreationForm();

    std::string getTarget() const;

    void execute(Bureaucrat const & executor) const;

};

#endif