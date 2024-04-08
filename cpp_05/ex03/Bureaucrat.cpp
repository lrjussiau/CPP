#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	this->_grade = src._grade;
	return *this;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

std::string	Bureaucrat::getName() const {
	return this->_name;
}

void	Bureaucrat::incrementGrade() {
	if (this->_grade < 2)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade > 149)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}

void	Bureaucrat::signForm(AForm &form) {
	if (this->_grade > form.getGradeToSign())
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because grade to low" << std::endl;
	else if (form.getSigned() == true)	
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because form already signed" << std::endl;
	else
	{
		form.beSigned(*this);
		std::cout << this->_name << " sign " << form.getName() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm &form) {
	if (this->_grade > form.getGradeToExec())
		throw GradeTooLowException();
	if (form.getSigned() == false)
		throw IsSignedException();
	form.execute(*this);
	std::cout << _name << " execute " << form.getName() << std::endl;
}

std::ostream &  operator<<(std::ostream & o, const Bureaucrat& rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}