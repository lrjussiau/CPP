#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class AForm {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		AForm(std::string name, int gradeToSign, int gradeToExec);
		virtual ~AForm();
		AForm(const AForm &src);

		AForm &operator=(const AForm &src);
		std::string	getName() const;
		bool		getSigned();
		int			getGradeToSign() const;
		int			getGradeToExec() const;

		void		beSigned(Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat& bureaucrat) const = 0;
};

std::ostream &  operator<<(std::ostream & o, AForm const & rhs);

#endif