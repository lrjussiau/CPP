#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat {

	private:

		const std::string	_name;
		int					_grade;

	public:

		Bureaucrat(const std::string name, int grade);
		virtual ~Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);

		int			getGrade() const;
		std::string	getName() const;

		void		incrementGrade();
		void		decrementGrade();
		void		signForm(AForm &form);
		void		executeForm(AForm &form);
};

std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs);

class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw () {
			return ("Grade too high");
		}
};

class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw () {
			return ("Grade too low");
		}
};

class IsSignedException : public std::exception {
	public:
		virtual const char *what() const throw () {
			return ("Form is not signed");
		}
};

#endif