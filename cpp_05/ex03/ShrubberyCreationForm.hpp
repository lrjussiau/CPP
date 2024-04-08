#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "Form.hpp"

class ShrubberyCreationForm : public AForm
{
private:

    std::string _target;

public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
    
    void execute(const Bureaucrat& bureaucrat) const;
};

#endif