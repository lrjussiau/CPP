#include "Intern.hpp"

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern &Intern::operator=(const Intern &src) {
	(void) src;
	return (*this);
}

AForm	*Intern::makeForm(std::string form, std::string target) {

	AForm  *AForm[] = { 
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
    std::string levels[] = { "shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    while (i < 3 && levels[i].compare(form))
        i++ ;
    if (i < 3)
	{
		std::cout << "Inter create " << form << std::endl;
        return(AForm[i]);
	}
	std::cout << "Inter can not create " << form << std::endl;
	return (NULL);
}