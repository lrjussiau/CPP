#include "Bureaucrat.hpp"

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

std::ostream &  operator<<(std::ostream & o, const Bureaucrat& rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}