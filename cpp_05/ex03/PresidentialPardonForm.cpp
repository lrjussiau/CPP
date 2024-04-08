#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm("Presidential Pardon Form", 25, 5), _target(src._target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    (void)rhs;
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const {
	if (bureaucrat.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}