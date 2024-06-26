#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Form {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		Form(std::string name, int gradeToSign, int gradeToExec);
		virtual ~Form();
		Form(const Form &src);

		Form &operator=(const Form &src);
		std::string	getName() const;
		bool		getSigned();
		int			getGradeToSign() const;
		int			getGradeToExec() const;

		void		beSigned(Bureaucrat &bureaucrat);

};

std::ostream &  operator<<(std::ostream & o, Form const & rhs);

#endif