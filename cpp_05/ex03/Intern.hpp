#ifndef INTERN_H
# define INTERN_H

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

	private:

	public:

		Intern();
		virtual ~Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);

		AForm *makeForm(std::string form, std::string target);
};

#endif