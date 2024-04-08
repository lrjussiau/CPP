#include "Form.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name) , _gradeToSign(gradeToSign) , _gradeToExec(gradeToExec) {
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1  || gradeToExec < 1)
		throw GradeTooHighException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &src) : _name(src._name) , _gradeToSign(src._gradeToSign) , _gradeToExec(src._gradeToExec) {
}

AForm& AForm::operator=(const AForm &src) {
	this->_signed = src._signed;
	return *this;
}

std::string	AForm::getName() const {
	return this->_name;
}

bool	AForm::getSigned() {
	return this->_signed;
}

int	AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int	AForm::getGradeToExec() const {
	return this->_gradeToExec;
}

void		AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	else {
		this->_signed = true;
	}
}

std::ostream&   operator<<( std::ostream& o, const AForm& rhs ) {
    o << "------------- AForm Info -------------" << std::endl;
    o << "AForm name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeToSign() << std::endl
      << "Grade to execute: " << rhs.getGradeToExec();
    return o;
}