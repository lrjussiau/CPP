#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm("Robotomy Request Form", 72, 45), _target(src._target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    (void)rhs;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
	if (bureaucrat.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	static int  i;
    if ( i % 2 == 0 )
        std::cout << "BZZZZZT! " << _target << " has been robotomized!" << std::endl;
    else
        std::cout << "Robotomy failed! " << _target << " is still alive." << std::endl;
    i++;
}