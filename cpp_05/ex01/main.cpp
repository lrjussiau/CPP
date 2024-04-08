#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try
	{
		std::cout << "Bureaucrate 1 :" << std::endl;
		Bureaucrat b1("Tom", 25);
		Form docu("Doc 1", 28, 28);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		b1.signForm(docu);
		b1.signForm(docu);
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Bureaucrate 2 :" << std::endl;
		Bureaucrat b2("Paul", 25);
		Form doc("Doc 2", 24, 24);
		std::cout << b2 << std::endl;
		std::cout << doc << std::endl;
		std::cout << std::endl;
		b2.signForm(doc);
	}
	catch (GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
	catch (GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }

}