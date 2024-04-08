#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main() {
	try
	{
		PresidentialPardonForm p_form("The president");
		RobotomyRequestForm r_form("Tonio");
		ShrubberyCreationForm s_form("Zes");
		Bureaucrat tony("Tony", 32);

		tony.signForm(s_form);
		tony.executeForm(s_form);
		tony.executeForm(s_form);
		tony.executeForm(s_form);

		tony.signForm(r_form);
		tony.executeForm(r_form);
		tony.signForm(r_form);
		tony.executeForm(r_form);

		tony.signForm(p_form);
		tony.executeForm(p_form);
	}
	catch (GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
	catch (GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
	catch (IsSignedException &e) {
        std::cout << e.what() << std::endl;
    }

}