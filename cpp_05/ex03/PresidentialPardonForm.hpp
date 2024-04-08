#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "Form.hpp"

class PresidentialPardonForm : public AForm
{
private:

    std::string _target;

public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
    
    void execute(const Bureaucrat& bureaucrat) const;
};

#endif