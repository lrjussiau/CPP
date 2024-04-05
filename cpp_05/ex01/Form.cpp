#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name) , _gradeToSign(gradeToSign) , _gradeToExec(gradeToExec) {
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1  || gradeToExec < 1)
		throw GradeTooHighException();
}

Form::~Form() {}

Form::Form(const Form &src) : _name(src._name) , _gradeToSign(src._gradeToSign) , _gradeToExec(src._gradeToExec) {
}

Form& Form::operator=(const Form &src) {
	this->_signed = src._signed;
	return *this;
}

std::string	Form::getName() {
	return this->_name;
}

bool	Form::getSigned() {
	return this->_signed;
}

int	Form::getGradeToSign() {
	return this->_gradeToSign;
}

int			Form::getGradeToExec() {
	return this->_gradeToExec;
}

void		Form::beSigned(Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade())
}

std::ostream&   operator<<( std::ostream& o, const Form& rhs ) {
    o << "------------- Form Info -------------" << std::endl;
    o << "Form name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeToSign() << std::endl
      << "Grade to execute: " << rhs.getGradeToExec();
    return o;
}